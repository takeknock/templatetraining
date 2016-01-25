#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "DualExpression.h" 

namespace strcp {
    template <typename E1, typename E2>
    class Mult : DualExpression<Mult<E1, E2> > {
    public:
        typedef typename DualExpression<Mult<E1, E2> >::type result_type;
        static result_type apply(
            const E1& e1, const E2& e2)
        {
            return e1 * e2;
        }
    };
} // namespace strcp {
#endif // FUNCTIONS_H_INCLUDED
