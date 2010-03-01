
//          Copyright Joakim Karlsson & Kim Gräsman 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <tests/igloo_self_test.h>

using namespace igloo;

struct Common : public ContextProvider<Common, TestFixtureBase>
{
  virtual ~Common() {}
  virtual void SpecificSetUp() = 0;
  
  void SetUp()
  {
    SpecificSetUp();
  }
  
  Spec(TestIt)
  {
    Assert::That(val, Is().LessThan(4));
  }
  
  int val;
};

SubContext(Specific1, Common)
{
  virtual ~Specific1() {}
  void SpecificSetUp()
  {
    val = 3;
  }
};

SubContext(Specific2, Common)
{
  virtual ~Specific2() {}
  void SpecificSetUp()
  {
    val = 2;
  }
};
