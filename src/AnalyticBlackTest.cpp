#include "AnalyticBlackTest.h"
#include "AnalyticBlack.h"
#include "Accessor.h"
#include <cppunit/extensions/HelperMacros.h>

class BlackAnalyticMember {
public:
    typedef const double strcp::AnalyticBlack::* type;
};

template class Initializer<BlackAnalyticMember, &strcp::AnalyticBlack::_forwardRate>;
CPPUNIT_TEST_SUITE_REGISTRATION(AnalyticBlackTest);

void AnalyticBlackTest::setUp()
{
}

void AnalyticBlackTest::testConstructor()
{
    const double forwardRate = 0.01;
    strcp::AnalyticBlack a(forwardRate);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(forwardRate, 
        a.*Accessor<BlackAnalyticMember>::value, 3);
}

void AnalyticBlackTest::testCalculatePrice()
{

}

void AnalyticBlackTest::testCalculateD1()
{
}

void AnalyticBlackTest::testCalculateD2()
{
}
void AnalyticBlackTest::tearDown()
{
}
