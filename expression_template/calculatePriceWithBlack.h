#ifndef CALCULATE_PRICE_WITH_BLACK_H_INCLUDED
#define CALCULATE_PRICE_WITH_BLACK_H_INCLUDED

#include "BlackTraits.h"
namespace cp {
    // interface of black model
    template <typename F, typename K, typename V, typename T, typename D>
    typename BlackTraits<F, K, V, T, D>::result_type calculatePriceWithBlack(const F& f,
        const K& k, const V& v, const T& t, const D& d)
    {
        // thought to input double, Dual and so on.
        return BlackTraits<F, K, V, T, D>::apply(f(), k(), v(), t(), d()); 
    }
} // namespace cp {
#endif // CALCULATE_PRICE_WITH_BLACK_H_INCLUDED
