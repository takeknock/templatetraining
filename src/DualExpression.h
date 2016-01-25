#ifndef DUAL_EXPRESSION_H_INCLUDED
#define DUAL_EXPRESSION_H_INCLUDED

namespace strcp {
    template <typename E>
    class DualExpression {
    public:
        typedef DualExpression<E> type;
        const E& operator()() const
        {
            return static_cast<const E&> (*this);
        }
    };
}// namespace strcp {

#endif // DUAL_EXPRESSION_H_INCLUDED
