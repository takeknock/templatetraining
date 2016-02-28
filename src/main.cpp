#include <iostream>

#include <boost/math/distributions/normal.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "Dual.h"
#include "dual_expression.h"


namespace cp {
    // f(x): x |-> x * x
    template <typename V>
    Dual<V> simpleFunction(Dual<V> x)
    {
        return x * x;
    }
    
    // f(x): x |-> x * x + 3.0
    template <typename V>
    Dual<V> simpleFunction2(Dual<V> x, V b)
    {
        return x * x + b;
    }

    // f(x): x |-> x * x * y 
    template <typename V>
    Dual<V> simpleFunction3(Dual<V> x, double y)
    {
        return x * x * y;
    }

    // f(x): x |-> x * x * x / y 
    template <typename V>
    Dual<V> simpleFunction4(Dual<V> x, double y)
    {
        return x * x * x / y;
    }

} // namespace cp


int main()
{
    namespace ublas = boost::numeric::ublas;
    const double strike = 1.0;
    const double maturity = 10.0;
    const double volatility = 0.2;
    const double forwardRate = 0.1;
    // check equation
    const double dayCountFraction = 20 / 360;

    ublas::vector<double> discountFactor(5);
    discountFactor[0] = 0.99; // 6M 
    discountFactor[1] = 0.99; // 1Y 
    discountFactor[2] = 0.98; // 1Y6M
    discountFactor[3] = 0.96; // 2Y
    discountFactor[4] = 0.94; // 2Y6M

    ublas::vector<double> yield(4);
    // let day count convention be ACT360. 
    // without thinking target date is whether business day or not.
    
    // 6M to 1Y 
    yield[0] = 180.0 / 360.0 * (discountFactor[0] / discountFactor[1] - 1); 
    // 1Y to 1Y6M
    yield[1] = 180.0 / 360.0 * std::log(discountFactor[1] / discountFactor[2]); 
    // 1Y6M to 2Y
    yield[2] = 180.0 / 360.0 * std::log(discountFactor[2] / discountFactor[3]); 
    // 2Y to 2Y6M
    yield[3] = 180.0 / 360.0 * std::log(discountFactor[3] / discountFactor[4]); 

    std::cout << std::setprecision(15) << yield[3] << std::endl;

    //cp::black<double, double, double, double, double> f;
    //double price = f(strike, maturity, volatility, forwardRate, dayCountFraction);
    //std::cout << price << std::endl;

    // TODO: be able to input other type as template arguments 

    cp::Dual<double> a(10.0, 1.0);
    cp::Dual<double> b(20.0, 0.0);
    
    cp::Dual<double> p = a + b;
    cp::Dual<double> mi = a - b;
    cp::Dual<double> mu = a * b;
    cp::Dual<double> div = a / b;

    cp::Dual<double> test = cp::simpleFunction(a);
    std::cout << test._value << std::endl;
    std::cout << test._derivative << std::endl;

    cp::Dual<double> test2 = cp::simpleFunction2(a, 3.0);
    std::cout << test2._value << std::endl;
    std::cout << test2._derivative << std::endl;

    cp::Dual<double> test3 = cp::simpleFunction3(a, 3.0);
    std::cout << test3._value << std::endl;
    std::cout << test3._derivative << std::endl;

    cp::Dual<double> test4 = cp::simpleFunction4(a, 3.0);
    std::cout << test4._value << std::endl;
    std::cout << test4._derivative << std::endl;

    //std::cout << p._derivative << std::endl;
    //std::cout << mi._derivative << std::endl;
    //std::cout << mu._derivative << std::endl;
    //std::cout << div._derivative << std::endl;

    return 0;
}
