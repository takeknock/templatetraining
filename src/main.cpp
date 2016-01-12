#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

#include <iostream>
#include <boost/math/distributions/normal.hpp>
#include "AnalyticBlack.h"


int main() 
{

    CPPUNIT_NS::TestResult controller;

    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);

    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener(&progress);

    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CppUnit::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);

    CPPUNIT_NS::CompilerOutputter outputter(&result, CPPUNIT_NS::stdCOut());
    outputter.write();

    const double notional = 10000;
    const double strike = 0.08;
    const double forwardRate1Yto15m = 0.07;
    const double dt = 0.25;
    const double yield = 0.065;
    const double expiry = 1.25;
    const double volatility = 0.2;
    const double fixingTime = 1.0;

    const double discountFactor = std::exp(-expiry * yield);
    const double d1 = (std::log(forwardRate1Yto15m / strike)
        + volatility * volatility * fixingTime * 0.5) /
            (volatility * std::sqrt(fixingTime));

    const double d2 = d1 - volatility * std::sqrt(fixingTime);
    boost::math::normal norm(0, 1);

    const double price = notional * dt * discountFactor 
        * (forwardRate1Yto15m * cdf(norm, d1) - strike * cdf(norm, d2));

    std::cout << d1 << std::endl;
    std::cout << d2 << std::endl;
    std::cout << price << std::endl;

    strcp::AnalyticBlack black(forwardRate1Yto15m);
    const double price2 = black.calculatePrice(notional, strike, dt, yield,
        expiry, volatility, fixingTime);
    std::cout << price2 << std::endl;

    return 0;
}

