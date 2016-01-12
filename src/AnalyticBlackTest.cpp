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
    const double forwardRate = 0.07;
    const double notional = 10000;
    const double strike = 0.08;
    const double dt = 0.25;
    const double yield = 0.065;
    const double expiry = 1.25;
    const double volatility = 0.2;
    const double fixingTime = 1.0;
    strcp::AnalyticBlack a(forwardRate);
    CPPUNIT_ASSERT_DOUBLES_EQUAL(5.1900459174405, a.calculatePrice(notional, strike,
        dt, yield, expiry, volatility, fixingTime), 1e-08);

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
