#include <boost/math/distributions/normal.hpp>
#include "AnalyticBlack.h"
#include "NewtonMethod.h"

namespace strcp {

    AnalyticBlack::AnalyticBlack(const double forwardRate)
    : _forwardRate(forwardRate)
    {
    }

    AnalyticBlack::~AnalyticBlack()
    {
    }

    const double AnalyticBlack::calculatePrice(const double notional, 
        const double strike, const double dt, const double yield,
        const double expiry, const double volatility, 
        const double fixingTime)
    {
        boost::math::normal norm(0,1);
        const double d1 = AnalyticBlack::calculateD1(fixingTime, volatility, strike);
        const double d2 = AnalyticBlack::calculateD2(d1, volatility, fixingTime);
        const double discountFactor = std::exp(-expiry * yield);
        return notional * dt * discountFactor 
            * (_forwardRate * cdf(norm, d1) - strike * cdf(norm, d2));

    }

    const double AnalyticBlack::calculateD1(const double fixingTime, 
        const double volatility, const double strike)
    {
        return (std::log(_forwardRate / strike)
            + volatility * volatility * fixingTime * 0.5) 
                / (volatility * std::sqrt(fixingTime));
    }

    const double AnalyticBlack::calculateD2(const double d1, 
        const double volatility, const double fixingTime)
    {
        return d1 - volatility * std::sqrt(fixingTime);
    }

    const double calculateVolatility(const double notional, const double strike,
        const double dt, const double yield, const double expiry,
        const double fixintTime, const double price)
    {
        //use Newton Method.
        return 0.0;
    }

} // namespace strcp
