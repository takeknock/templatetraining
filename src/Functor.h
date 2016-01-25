#ifndef FUNCTOR_H_INCLUDED
#define FUNCTOR_H_INCLUDED

#include "DualExpression.h" 

namespace strcp {
    template <typename E1, typename E2>
    struct DualPlus {
        typedef typename Plus<DualExpression<E1>&, DualExpression<E2>& >::type
            result_type;
        static result_type apply(
            const DualExpression<E1>& e1, const DualExpression<E2>& e2)
        {
            return Dual<result_type>(e1._value + e2._value,
                e1._derivative + e2._derivative);
        }
    };

    template <typename E1, typename E2>
    struct DualMinus {
        typedef typename Minus<DualExpression<E1>&, DualExpression<E2>& >::type
            result_type;
        static result_type apply(
            const DualExpression<E1>& e1, const DualExpression<E2>& e2)
        {
            return Dual<result_type>(e1._value - e2._value,
                e1._derivative - e2._derivative);
        }
    };

    template <typename E1, typename E2>
    struct DualMult {
        typedef typename Mult<DualExpression<E1>&, DualExpression<E2>& >::type
            result_type;
        static result_type apply(
            const DualExpression<E1>& e1, const DualExpression<E2>& e2)
        {
            return Dual<result_type>(e1._value * e2._value,
                e1._value * e2._derivative + e1._derivative * e2._value);
        }
    };

    template <typename E1, typename E2>
    struct DualDiv {
        typedef typename Div<DualExpression<E1>&, DualExpression<E2>& >::type
            result_type;
        static result_type apply(
            const DualExpression<E1>& e1, const DualExpression<E2>& e2)
        {
            return Dual<result_type>(e1._value / e2._value,
                (e2._value * e1._derivative - e1._value * e2._derivative)
                /(e2._value * e2._value));
        }
    };
} // namespace strcp
#endif // FUNCTOR_H_INCLUDED
