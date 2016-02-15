#ifndef DUAL_H_INCLUDED
#define DUAL_H_INCLUDED

#include <boost/numeric/ublas/vector.hpp>
//#include "dual_expression.h"

namespace cp {
//最終的に偏微分したいが、その際、derivativeがvectorの形となるが、その初期値はどのように与えるのか
//
    template <typename V, typename D>
    class Dual {
    public:
        //namespace ublas = boost::numeric::ublas;
        typedef V value_type;
        typedef typename boost::numeric::ublas::vector<D> vector_type;
    public:
        // first, 1 dim.
        Dual(value_type value, value_type derivative)
        : _value(value), _derivative(derivative)
        {
        }

    public:
        value_type _value;
        value_type _derivative;
    };

    // operators as free functions
    Dual<double, double> operator +(
        const Dual<double, double>& x, const Dual<double, double>& y)
    {
        return Dual<double, double>(x._value + y._value, x._derivative + y._derivative);
    }

    Dual<double, double> operator -(
        const Dual<double, double>& x, const Dual<double, double>& y)
    {
        return Dual<double, double>(x._value - y._value, x._derivative - y._derivative);
    }

    Dual<double, double> operator *(
        const Dual<double, double>& x, const Dual<double, double>& y)
    {
        return Dual<double, double>(x._value * y._value, 
            x._value * y._derivative + x._derivative * y._value);
    }

    Dual<double, double> operator /(
        const Dual<double, double>& x, const Dual<double, double>& y)
    {
        return Dual<double, double>(x._value / y._value, 
            (y._value * x._derivative - x._value * y._derivative) 
                / (y._value * y._value));
    }


} // namespace cp

#endif // DUAL_H_INCLUDED
