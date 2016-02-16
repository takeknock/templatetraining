#ifndef BLACK_TRAITS_H_INCLUDED
#define BLACK_TRAITS_H_INCLUDED

#include "ForwardBlackTraits.h"

namespace cp {
    template <typename K, typename T, typename V, typename F, typename D>
    struct BlackTraits {
        typedef ForwardBlackTraits<K, T, V, F> FwdBl;
        //typedef FuncBinaryTraits<D, typename FwdBl::type, scalar_mult> Disc;
        //typedef typename Disc::type result_type;
        typedef typename FwdBl::result_type result_type;
    
        static result_type apply(const K& k, const T& t, const V& v, const F& f, 
            const D& d)
        {
            //return Disc::apply(d, fwdbl::apply(f, k, v, t));
            return d * FwdBl::apply(k, t, v, f);
        }
    };
} // namespace strcp {

#endif // BLACK_TRAITS_H_INCLUDED
