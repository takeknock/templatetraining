#include <iostream>

#include <boost/math/distributions/normal.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

#include "Dual.h"
#include "dual_expression.h"


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

    namespace ublas = boost::numeric::ublas;
    //const double strike = 1.0;
    //const double maturity = 10.0;
    //const double volatility = 0.2;
    //const double forwardRate = 0.1;
    //// check equation
    //const double dayCountFraction = 20 / 360;

    ublas::vector<double> discountFactor(9);
    discountFactor[0] = 0.9999; // O/N
    discountFactor[1] = 0.9988; // T/N
    discountFactor[2] = 0.9912; // 1W 
    discountFactor[3] = 0.9891; // 1M
    discountFactor[4] = 0.98; // 6M 
    discountFactor[5] = 0.96; // 1Y 
    discountFactor[6] = 0.94; // 1Y6M
    discountFactor[7] = 0.93; // 2Y
    discountFactor[8] = 0.92; // 2Y6M


    ublas::vector<cp::Dual<double> > forwardLibor(9);
    // Let day count convention be ACT360, 
    // without thinking target date is whether business day or not.
    
    // today to O/N
    //forwardLibor[0] = 
    //    cp::Dual<double>(1.0 / 360.0 * (1.0 / discountFactor[0] - 1.0));
    //// O/N to T/N
    //forwardLibor[1] =
    //    cp::Dual<double>(1.0 / 360.0 * (discountFactor[0] / discountFactor[1] - 1.0));
    //// T/N to 1W
    //forwardLibor[2] =
    //    cp::Dual<double>(5.0 / 360.0 * (discountFactor[1] / discountFactor[2] - 1.0));
    //// 1W to 1M
    //forwardLibor[3] =
    //    cp::Dual<double>(180.0 / 360.0 * (discountFactor[2] / discountFactor[3] - 1.0));
    //// 1M to 6M
    //forwardLibor[4] =
    //    cp::Dual<double>(180.0 / 360.0 * (discountFactor[3] / discountFactor[4] - 1.0));
    //// 6M to 1Y 
    //forwardLibor[5] =
    //    cp::Dual<double>(180.0 / 360.0 * (discountFactor[4] / discountFactor[5] - 1.0)); 
    //// 1Y to 1Y6M
    //forwardLibor[6] =
    //    cp::Dual<double>(180.0 / 360.0 * (discountFactor[5] / discountFactor[6] - 1.0)); 
    //// 1Y6M to 2Y
    //forwardLibor[7] =
    //    cp::Dual<double>(180.0 / 360.0 * (discountFactor[6] / discountFactor[7] - 1.0)); 
    //// 2Y to 2Y6M
    //forwardLibor[8] =
    //    cp::Dual<double>(180.0 / 360.0 * (discountFactor[7] / discountFactor[8] - 1.0)); 


    // example: calculate 6M caplet
    boost::math::normal norm(0,1);

    const double strike = 0.01;
    const double volatility = 0.2;
    const cp::Dual<double> forwardLibor(180.0 / 360.0 
        * (discountFactor[3] / discountFactor[4] - 1.0));

    const double d1 = (std::log(forwardLibor / strike)
            + 0.5 * volatility * volatility * 30 / 360) 
                / (volatility * std::sqrt(30 / 360));

    const double d2 = (std::log(forwardLibor / strike)
            - 0.5 * volatility * volatility * 30 / 360) 
                / (volatility * std::sqrt(30 / 360));

    const cp::Dual<double> capletPrice6m = 180 / 360 * discountFactor[4] * (forwardLibor[4]) * cdf(norm, d2) - strike * cdf(norm, d2); 

    //cp::black<double, double, double, double, double> f;
    //double price = f(strike, maturity, volatility, forwardRate, dayCountFraction);
    //std::cout << price << std::endl;

    // TODO: be able to input other type as template arguments 


    // for test
    const double a = 2.0;
    const cp::Dual<double> b(10.0);
    
    cp::Dual<double> p = a + b;
    cp::Dual<double> mi = a - b;
    cp::Dual<double> mu = a * b;
    cp::Dual<double> div = a / b;


    std::cout << p._derivative << std::endl;
    std::cout << mi._derivative << std::endl;
    std::cout << mu._derivative << std::endl;
    std::cout << div._derivative << std::endl;

    return 0;
}
