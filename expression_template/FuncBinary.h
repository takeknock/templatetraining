#ifndef FUNCBINARY_H_INCLUDED
#define FUNCBINARY_H_INCLUDED

namespace cp {
    template <typename X, typename Y>
    class FuncBinary {

    };

    template <typename X, typename Y, template <typename, typename> F>
    struct FuncBinaryTraits {
    public:
        typedef promote_traits<X::value_type, Y::value_type>::type result_type;

    };
} // namespace cp {

#endif // FUNCBINARY_H_INCLUDED

