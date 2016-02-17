#ifndef CON_TRAITS_H_INCLUDED
#define CON_TRAITS_H_INCLUDED

#include "D2Traits.h"
#include "FuncUnaryTraits.h"
#include "FuncBinaryTraits.h"

namespace cp {
    template <typename F, typename K, typename V, typename T>
    struct CoNTraits {
        typedef D2Traits<F, K, V, T> D2;
        typedef FuncUnaryTraits<typename D2::type, scalar_normdist> N2;
        typedef FuncBinaryTraits<F, typename D2::type, scalar_mult> Mult;
        typedef typename Mult::type type;

        static type apply(cosnt F& f, const K& k, const V& v, const T& t)
        {
            return Mult::apply(f, N2::apply(D2::apply(f, k, v, t)));
        }
    };

} // namespace cp
#endif // CON_TRAITS_H_INCLUDED
