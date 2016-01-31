#ifndef AON_TRAITS_H_INCLUDED
#define AON_TRAITS_H_INCLUDED
namespace strcp {
    template <typename F, typename K, typename V, typename T>
    struct AoNTraits {
        typedef D1Traits<F, K, V, T> D1;
        typedef FuncUnaryTraits<typename D1::type, scalar_normdist> N1;
        typedef FuncBinaryTraits<F, typename D1::type, scalar_mult> Mult;
        typedef typename Mult::type type;

        static type apply(cosnt F& f, const K& k, const V& v, const T& t)
        {
            return Mult::apply(f, N1::apply(D1::apply(f, k, v, t)));
        }
    };

} // namespace strcp
#endif // AON_TRAITS_H_INCLUDED
