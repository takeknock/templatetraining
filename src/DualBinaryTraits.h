#ifndef DUAL_BINARY_TRAITS_H_INCLUDED
#define DUAL_BINARY_TRAITS_H_INCLUDED
namespace strcp {
    template <typename L, typename R, typename F>
    class DualBinary {
    public:
        typedef F<typename L::result_type, typename R::_type> functor_type;
        typedef typename functor_type::result_type result_type;

        template <typename X>
        result_type operator()(const X& x) const
        {
            return functor_type::apply(_l(x), _r(x)); 
        }
        typename L::const_closure_type _l;
        typename R::const_closure_type _r;
    };

    template <typename L, typename R, template <typename, typename> class F>
    struct DualBinaryTraits {


    };

} // namespace strcp
#endif // DUAL_BINARY_TRAITS_H_INCLUDED
