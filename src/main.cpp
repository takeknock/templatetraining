#include <iostream>
#include "Dual.h"

template <typename K, typename T, typename V, typename F>
class black {
public:
    double operator()(const K& strike, const T& maturity, 
        const V& volatility, const F& forwardRate)
    {
        return strike;
    }

};

int main()
{
    const double strike = 1.0;
    const double maturity = 10.0;
    const double volatility = 0.2;
    const double forwardRate = 0.1;

    //black<double, double, double, double> b;
    //double price = b(strike, maturity, volatility, forwardRate);
    //std::cout << price << std::endl;

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
