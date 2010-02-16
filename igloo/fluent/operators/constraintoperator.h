
//          Copyright Joakim Karlsson & Kim Gräsman 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef IGLOO_CONTRAINTOPERATOR_H
#define IGLOO_CONTRAINTOPERATOR_H

namespace igloo {
  
  struct ConstraintOperator
  {
    virtual ~ConstraintOperator() {}
    
    virtual void PerformOperation(ResultStack& result) = 0;
    virtual int Precedence() = 0;
    
  protected:
    void EvaluateOperatorsWithLessOrEqualPrecedence(OperatorStack& operators, ResultStack& result)
    {
      while(!operators.empty())
      {
        ConstraintOperator* op = operators.top();
        
        if(op->Precedence() > Precedence())
        {
          break;
        }
        
        op->PerformOperation(result);        
        operators.pop();
      }      
    }
    
    static void EvaluateAllOperatorsOnStack(OperatorStack& operators, ResultStack& result)
    {
      while(!operators.empty())
      {
        ConstraintOperator* op = operators.top();
        op->PerformOperation(result);        
        operators.pop();
      } 
    }
  };
    
  struct InvalidExpressionException
  {
    InvalidExpressionException(const std::string& message) : m_message(message)
    {
    }
    
    const std::string& Message() const
    {
      return m_message;
    }
    
    std::string m_message;
  };
  
}

#endif
