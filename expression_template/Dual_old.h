#ifndef DUAL_H_INCLUDED
#define DUAL_H_INCLUDED

#include "promote_traits.h"

namespace cp {
//最終的に偏微分したいが、その際、derivativeがvectorの形となるが、その初期値はどのように与えるのか
//
    template <typename V, typename D>
    class Dual : public dual_expression<Dual> {
        namespace ublas = boost::numeric::ublas;
    public:
        typedef typename V value_type;
        typedef typename ublas::vector<D> vector_type;
    public:
        // first, 1 dim.
        Dual(value_type value, value_type derivative)
        : _value(value), _derivative(derivative)
        {
        }

    private:
        value_type _value;
        value_type _derivative;
    };


    template <>
    struct promote_traits <Dual, Dual> {
    public:
        typedef Dual result_type;
    };

    template <>
    struct promote_traits <double, Dual> {
    public:
        typedef Dual result_type;
    };
    
    template <>
    struct promote_traits <Dual, double> {
    public:
        typedef Dual result_type;
    };

    // overloaded functors
    template <typename X, typename Y>
    class scalar_plus<dual_expression<X>, dual_expression<Y> > {
    public:
        typedef Dual result_type;
        static result_type apply(const X& x, const Y& y)
        {
            return Dual(x._value + y._value, x._derivative + y._derivative);
        }
    };

    template <typename X, typename Y>
    class scalar_minus<dual_expression<X>, dual_expression<Y> > {
    public:
        typedef Dual result_type;
        static result_type apply(const X& x, const Y& y)
        {
            return Dual(x._value - y._value, x._derivative - y._derivative);
        }
    };

    template <typename X, typename Y>
    class scalar_mult<dual_expression<X>, dual_expression<Y> > {
    public:
        typedef Dual result_type;
        static result_type apply(const X& x, const Y& y)
        {
            return Dual(x._value * y._value, );
        }
    };

    template <typename X, typename Y>
    class scalar_plus<dual_expression<X>, dual_expression<Y> > {
    public:
        typedef Dual result_type;
        static result_type apply(const X& x, const Y& y)
        {
            return Dual(x._value + y._value, x._derivative + y._derivative);
        }
    };

    // operators as free functions
    template <typename X, typename Y>
    typename FuncBinaryTraits<X, Y, scalar_plus>::result_type
        operator +(const duan_expression<X>& x, const dual_expression<Y>& y)
    {
        return typename FuncBinaryTraits<X, Y, dual_plus>::apply(x, y);
    }

    template <typename X, typename Y>
    typename FuncBinaryTraits<X, Y, scalar_minus>::result_type
        operator +(const dual_expression<X>& x, const dual_expression<Y>& y)
    {
        return typename FuncBinaryTraits<X, Y, dual_minus>::apply(x, y);
    }

    template <typename X, typename Y>
    typename FuncBinaryTraits<X, Y, scalar_mult>::result_type
        operator +(const dual_expression<X>& x, const dual_expression<Y>& y)
    {
        return typename FuncBinaryTraits<X, Y, dual_mult>::apply(x, y);
    }

    template <typename X, typename Y>
    typename FuncBinaryTraits<X, Y, scalar_div>::result_type
        operator +(const dual_expression<X>& x, const dual_expression<Y>& y)
    {
        return typename FuncBinaryTraits<X, Y, dual_div>::apply(x, y);
    }

    // 演算の取りうる型をDual<T>に限定したい
    struct plus
    {
        template<typename X, typename Y>
        promote_traits<X, Y>::result_type operator()(dual_expression<X> const& x, dual_expression<Y> const& y)
        {
            return ;
        }
    };


} // namespace cp




#endif // DUAL_H_INCLUDED
