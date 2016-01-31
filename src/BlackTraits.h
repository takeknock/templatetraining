#ifndef BLACK_TRAITS_H_INCLUDED
#define BLACK_TRAITS_H_INCLUDED

#include "Functions.h"

namespace strcp {
    template <typename E1, typename E2, typename F>
    class Mult {
    public:
        typedef BinaryTraits<E1, E2>::type result_type;
        static result_type apply(const E1& e1, const E2& e2)
        {
            //return F::apply(e1, e2);
            return e1 * e2;
        }
    };

    template <typename F, typename K, typename V, typename T>
    struct ForwardBlackTraits {
       typedef  
    static 


    };


    template <typename F, typename K, typename V, typename T, typename D>
    struct BlackTraits {
        typedef ForwardBlackTraits<F, K, V, T> FwdBl;
        typedef FuncBinaryTraits<D, typename FwdBl::type, scalar_mult> Disc;
        typedef typename Disc::type type;
    
        static type apply(const F& f, const K& k, const V& v, const T& t,
            const D& d)
        {
            return Disc::apply(d, fwdbl::apply(f, k, v, t));
        }
    };
} // namespace strcp {

#endif // BLACK_TRAITS_H_INCLUDED
