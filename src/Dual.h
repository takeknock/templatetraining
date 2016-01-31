#ifndef DUAL_H_INCLUDED
#define DUAL_H_INCLUDED
#include <boost/numeric/ublas/vector.hpp>
#include "BinaryTraits.h"
#include "Functor.h"

namespace strcp {
    template <typename T>
    class Dual {
    namespace ublas = boost::numeric::ublas;
    public:
        Dual(T a, T b)
        :_value(a), _derivative(b)
        {
        }

        ~Dual()
        {
        }
    
    private:
        T _value;
        T _derivative;
    };

    template<typename L, typename R, typename O>
    struct BinaryTraits {
        typedef BinaryTraits<L, R, O> type;
        typedef O<L, R>::result_type result_type;

        static result_type apply(const L& l, const R& r, const O& o)
        {
            return o::apply(l, r);
        }
    };

    template <typename L, typename R>
    typename BinaryTraits<L, R, DualPlus>::type
        operator +(const Dual<L>& x, const Dual<R>& y)
    {
        return typename BinaryTraits<L, R, DualPlus>::type
            Dual(x._value + y._value, x._derivative + y._derivative);
    }

    template <typename L, typename R>
    typename BinaryTraits<L, R, DualMinus>::type
        operator -(const Dual<L>& x, const Dual<R>& y)
    {
        return typename BinaryTraits<L, R, DualMinus>::type
            Dual(x._value - y._value, x._derivative - y._derivative);
    }

    template <typename L, typename R>
    typename BinaryTraits<L, R, DualMult>::type
        operator *(const Dual<L>& x, const Dual<R>& y)
    {
        return typename BinaryTraits<L, R, DualMult>::type
            Dual(x._value * y._value, 
                x._value * y._derivative + x._derivative * y._value);
    }

    template <typename L, typename R>
    typename BinaryTraits<L, R, DualDiv>::type
        operator /(const Dual<L>& x, const Dual<R>& y)
    {
        return typename BinaryTraits<L, R, DualDiv> Dual<result_type>(x._value / y._value,
            (y._value * x._derivative - x._value * y._derivative)
            /(y._value * y._value));
    }
} // namespace strcp 
#endif //  DUAL_H_INCLUDED
