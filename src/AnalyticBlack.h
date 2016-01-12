#ifndef ANALYTICBLACK_H_INCLUDED
#define ANALYTICBLACK_H_INCLUDED

namespace strcp {
    class AnalyticBlack {
    public:
        AnalyticBlack(const double forwardRate); 
        ~AnalyticBlack();
        const double calculatePrice(const double notional, const double strike,
             const double dt, const double yield,
             const double expiry, const double volatility, 
             const double fixingTime);

    private:
        const double _forwardRate;
        
        const double calculateD1(const double fixingTime, 
            const double volatility, const double strike);
        const double calculateD2(const double d1, const double volatility,
            const double fixingTime);
    };

} // namespace strcp
#endif // ANALYTICBLACK_H_INCLUDED
