#ifndef DUAL_BINARY_TRAITS_H_INCLUDED
#define DUAL_BINARY_TRAITS_H_INCLUDED
namespace strcp {
    template <typename L, typename R, typename F>
    class DualBinary {
    public:
        typedef F<typename L::result_type, typename R::result_type> functor_type;
        typedef typename functor_type::result_type result_type;

        template <typename X>
        result_type operator()(const X& x) const
        {
            return functor_type::apply(_l(x), _r(x)); 
        }
        typename L::const_closure_type _l;
        typename R::const_closure_type _r;
    };

    // traits
    template <typename L, typename R, template <typename, typename> class F>
    struct DualBinaryTraits {
        typedef DualBinary<L, R, F> type;
        static type apply(const L& l, const R& r)
        {
            return type(l, r);
        }
    };

    // functors
    template <typename L, typename R>
    struct DualPlus {
        typedef F<typename L::result_type, typename R::result_type> result_type;
        static result_type apply(const L& l, const R& r)
        {
            return Dual(x._value + y._value, x._derivative + y._derivative);
        }
    };
    template <typename L, typename R>
    struct DualMinus {
        typedef F<typename L::result_type, typename R::result_type> result_type;
        static result_type apply(const L& l, const R& r)
        {
            return Dual(x._value - y._value, x._derivative - y._derivative);
        }
    };

    template <typename L, typename R>
    struct DualMult {
        typedef F<typename L::result_type, typename R::result_type> result_type;
        static result_type apply(const L& l, const R& r)
        {
            return Dual(x._value * y._value, 
                x._value * y._derivative + x._derivative * y._value);
        }
    };

    template <typename L, typename R>
    struct DualDiv {
        typedef F<typename L::result_type, typename R::result_type> result_type;
        static result_type apply(const L& l, const R& r)
        {
            return Dual<result_type>(x._value / y._value,
                (y._value * x._derivative - x._value * y._derivative)
                    / (y._value * y._value));
        }
    };

} // namespace strcp
#endif // DUAL_BINARY_TRAITS_H_INCLUDED
