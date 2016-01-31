#ifndef D2_TRAITS_H_INCLUDED
#define D2_TRAITS_H_INCLUDED
namespace strcp {
    template <typename F, typename K, typename V, typename T>
    struct D2Traits {
        typedef D1Traits<F, K, V, T> D1;
        typedef StdevTraits<V, T> Sd;
        typedef FuncBinaryTraits<typename D1::type, typename Sd::type,
            scalar_minus> Minus;
        typedef Minus::type type;

        static type apply(const F& f, const K& k, const V& v, const T& t)
        {
            return Minus::apply(D1::apply(F, K, V, T), Sd::apply(v,t));
        }
    };
} // namespace strcp
#endif // D2_TRAITS_H_INCLUDED
