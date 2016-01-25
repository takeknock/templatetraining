#ifndef BINARY_TRAITS_H_INCLUDED
#define BINARY_TRAITS_H_INCLUDED

namespace strcp {
    template<typename L, typename R, template <typename, typename> class O>
    struct BinaryTraits {
    public:
        typedef O<L::result_type, R::result_type> type;

    
    };
} // namespace strcp {

#endif // BINARY_TRAITS_H_INCLUDED
