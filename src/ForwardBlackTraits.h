#ifndef FORWARD_BLACK_TRAITS_H_INCLUDED
#define FORWARD_BLACK_TRAITS_H_INCLUDED

//#include "AoNTraits.h"
//#include "CoNTraits.h"

namespace cp {
    template <typename K, typename T, typename V, typename F>
    struct ForwardBlackTraits {
        //typedef AoNTraits<F, K, V, T> AoN;
        //typedef CoNTraits<F, K, V, T> CoN;
        //typedef FuncBinaryTraits<typename AoN::type, typename CoN::type, 
        //    scalar_minus> Minus;
        //typedef typename Minus::type type;
        typedef double result_type;

        static result_type apply(const K& k, const T& t, const V& v, const F& f)
        {
            //return Minus::apply(AoN::apply(f, k, v, t), CoN::apply(f, k, v, t));
            return f * k; 
        }
    };
} // namespace strcp

#endif // FORWARD_BLACK_TRAITS_H_INCLUDED
