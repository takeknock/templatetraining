#ifndef DUAL_INCLUDED
#define DUAL_INCLUDED
#include "type_traits.h"

namespace dual {
    template <typename T>
    class Dual {
    public:
        Dual()
        :_value(0), _derivative(0)
        {
        }

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


    template <typename l, typename r>
    Dual<typename promote_traits<l, r>::type>
        operator +(const Dual<l>& x, const Dual<r>& y)
    {
        typedef typename promote_traits<l, r>::type result_type;
        return Dual<result_type>(x._value + y._value, x._derivative + y._derivative);
    }

    template <typename l, typename r>
    Dual<typename promote_traits<l, r>::type>
        operator -(const Dual<l>& x, const Dual<r>& y)
    {
        typedef typename promote_traits<l, r>::type result_type;
        return Dual<result_type>(x._value - y._value, x._derivative - y._derivative);
    }

    template <typename l, typename r>
    Dual<typename promote_traits<l, r>::type>
        operator *(const Dual<l>& x, const Dual<r>& y)
    {
        typedef typename promote_traits<l, r>::type result_type;
        return Dual<result_type>(x._value * y._value,
             x._value * y._derivative + x._derivative * y._value);
    }

    template <typename l, typename r>
    Dual<typename promote_traits<l, r>::type>
        operator /(const Dual<l>& x, const Dual<r>& y)
    {
        typedef typename promote_traits<l, r>::type result_type;
        return Dual<result_type>(x._value / y._value,
             (y._value * x._derivative - x._value * y._derivative)/(y._value * y._value);
    }
} // namespace dual
#endif
