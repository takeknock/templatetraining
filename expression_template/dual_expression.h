#ifndef DUAL_EXPRESSION_H_INCLUDED
#define DUAL_EXPRESSION_H_INCLUDED

namespace cp {
    template <typename E>
    class dual_expression {
    public:
        typedef dual_expression<E> type;
        const E& operator()() const
        {
            return static_cast<const E&> (*this);
        }
    };

} // namespace cp

#endif // DUAL_EXPRESSION_H_INCLUDED

