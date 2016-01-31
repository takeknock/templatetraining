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


    template <typename L, typename R>
    typename DualBinaryTraits<L, R, DualPlus>::type
        operator +(const Dual<L>& x, const Dual<R>& y)
    {
        return typename DualBinaryTraits<L, R, DualPlus>::apply(x, y);
    }

    template <typename L, typename R>
    typename DualBinaryTraits<L, R, DualMinus>::type
        operator -(const Dual<L>& x, const Dual<R>& y)
    {
        return typename DualBinaryTraits<L, R, DualMinus>::apply(x, y);
    }

    template <typename L, typename R>
    typename DualBinaryTraits<L, R, DualMult>::type
        operator *(const Dual<L>& x, const Dual<R>& y)
    {
        return typename DualBinaryTraits<L, R, DualMult>::apply(x, y);
    }

    template <typename L, typename R>
    typename DualBinaryTraits<L, R, DualDiv>::type
        operator /(const Dual<L>& x, const Dual<R>& y)
    {
        return typename DualBinaryTraits<L, R, DualDiv>::apply(x, y); 
    }
} // namespace strcp 
#endif //  DUAL_H_INCLUDED
