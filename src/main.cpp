#include <iostream>
#include "Dual.h"


int main()
{
    const double strike = 1.0;
    const double maturity = 10.0;
    const double volatility = 0.2;
    const double forwardRate = 0.1;
    // day count fraction ??
    // discount ??
    // check equation
    const double dayCountFraction = 20 / 360;

    //cp::black<double, double, double, double, double> f;
    //double price = f(strike, maturity, volatility, forwardRate, dayCountFraction);
    //std::cout << price << std::endl;


    // TODO: be able to input other type as template arguments 

    cp::Dual<double, double> a(10.0, 5.0);
    cp::Dual<double, double> b(20.0, 2.0);
    
    cp::Dual<double, double> p = a + b;
    cp::Dual<double, double> mi = a - b;
    cp::Dual<double, double> mu = a * b;
    cp::Dual<double, double> div = a / b;

    std::cout << p._derivative << std::endl;
    std::cout << mi._derivative << std::endl;
    std::cout << mu._derivative << std::endl;
    std::cout << div._derivative << std::endl;



    return 0;
}
