#ifndef IGLOO_IGLOO_H
#define IGLOO_IGLOO_H

#include <iostream>
#include <map>
#include <vector>
#include <sstream>

#include "syntax.h"
#include "assertionexception.h"
#include "testfixture.h"
#include "testrunner.h"
#include "assert.h"                

#include "constraints/equalsconstraint.h"
#include "constraints/isgreaterthanconstraint.h"
#include "constraints/islessthanconstraint.h"       
#include "constraints/containsconstraint.h"
#include "constraints/haslengthconstraint.h"
#include "constraints/startswithconstraint.h"
#include "constraints/endswithconstraint.h"

#define TestFixture(fixture) \
struct fixture; \
int fixture##_dummy = igloo::TestRunner::RegisterTestFixture( #fixture , new igloo::TestFixture<fixture>()); \
struct fixture : public igloo::TestFixture<fixture>
         
#define TestMethod(method) \
struct TestMethodRegistrar##method \
{ \
  TestMethodRegistrar##method() \
  { \
    IGLOO_FIXTURE_TYPE::RegisterTestMethod(#method, &IGLOO_FIXTURE_TYPE::method); \
  } \
} method##Registrar; \
\
void method()

#endif
