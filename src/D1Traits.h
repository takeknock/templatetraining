#ifndef D1_TRAITS_H_INCLUDED
#define D1_TRAITS_H_INCLUDED
namespace strcp {
    template <typename F, typename K, typename V, typename T>
    struct D1Traits {
        typedef LogTraits<F, K> LnFK;
        typedef StdevTraits<V, T> Sd;
        typedef Rational<double, 1, 2> Half;
        typedef FuncBinaryTraits<typename LnFK::type, typename Sd::type,
            scalar_div> X1;
        typedef FuncBinaryTraits<Half, typename Sd::type, scalar_mult> X2;
        typedef FuncBinaryTraits<typename X1::type, typename X2::type,
            scalar_plus> Plus;
        typedef typename Plus::type type;

        static type apply(const F& f, const K& k, const V& v, const T&t)
        {       
            return Plus::apply(X1::apply(LnFK::apply(f, k), Sd::apply(v, t),
                X2::apply(Half()), Sd::apply(v, t)));
        }

    };

} // namespace strcp
#endif // D1_TRAITS_H_INCLUDED
