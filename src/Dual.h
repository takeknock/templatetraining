#ifndef DUAL_INCLUDED
#define DUAL_INCLUDED
#include <boost/numeric/ublas/vector.hpp>
#include "BinaryTraits.h"
#include "Functor.h"

namespace dual {
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

    }

    template <typename L, typename R>
    Dual<typename promote_traits<L, R>::type>
        operator -(const Dual<L>& x, const Dual<R>& y)
    {
        return Dual<result_type>(x._value - y._value,
            x._derivative - y._derivative);
    }

    template <typename L, typename R>
    Dual<typename promote_traits<L, R>::type>
        operator *(const Dual<L>& x, const Dual<R>& y)
    {
        return 
    }


    template <typename L, typename R>
    Dual<typename promote_traits<L, R>::type>
        operator /(const Dual<L>& x, const Dual<R>& y)
    {
        typedef typename promote_traits<L, R>::type result_type;
        return Dual<result_type>(x._value / y._value,
            (y._value * x._derivative - x._value * y._derivative)
            /(y._value * y._value));
    }
} // namespace dual
#endif //  DUAL_INCLUDED
