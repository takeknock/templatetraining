#include <iostream>


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

    black<double, double, double, double> b;

    double price = b(strike, maturity, volatility, forwardRate);

    std::cout << price << std::endl;
    return 0;
}
