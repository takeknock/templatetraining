#ifndef BLACK_TRAITS_H_INCLUDED
#define BLACK_TRAITS_H_INCLUDED

#include "Functions.h"

namespace strcp {
    template <typename F, typename K, typename V, typename T, typename D>
    struct BlackTraits {
        typedef ForwardBlackTraits<F, K, V, T> FwdBl;
        typedef Mult::result_type result_type;
    
        static result_type apply(const D& d, const FwdBl& fwdbl)
        {
            return Mult::apply(d, fwdbl::apply(F, K, V, T));
        }
    };
} // namespace strcp {

#endif // BLACK_TRAITS_H_INCLUDED
