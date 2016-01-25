#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

#include <iostream>
#include "calculatePriceWithBlack.h"
//#include "AnalyticBlack.h"


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
    const double maturity = 1.25;
    const double volatility = 0.2;
    const double fixingTime = 1.0;

    // compile time
    const double price = strcp::calculatePriceWithBlack(
        forwardRate1Yto15m, strike, volatility, maturity, discountFactor);
    std::cout << price << std::endl;

    // execution time
    //strcp::AnalyticBlack black(forwardRate1Yto15m);
    //const double price2 = black.calculatePrice(notional, strike, dt, yield,
    //    expiry, volatility, fixingTime);
    //std::cout << price2 << std::endl;

    return 0;
}

