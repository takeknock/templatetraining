#ifndef DUAL_INCLUDED
#define DUAL_INCLUDED
#include <boost/numeric/ublas/vector.hpp>

//#include "type_traits.h"
namespace dual {
    namespace ublas = boost::numeric::ublas;
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

    // want to make zeroTraits
    //template<typename T>
    //struct zero_traits {
    //    typedef double value_type;
    //};

    //template<>
    //struct zero_traits<0> {
    //    ublas::vector<double>(10) = {0}; 
    //};


    template<typename l, typename r>
    struct promote_traits {
        typedef l result_type;
    };
    
    
    template<>
    struct promote_traits<int, double> {
        typedef double result_type;
    };
    
    template<>
    struct promote_traits<double, int> {
        typedef double result_type;
    };
    
    template<>
    struct promote_traits<double, Dual<double> > {
        typedef Dual<double> result_type;
    };
    
    template<>
    struct promote_traits<Dual<double>, double> {
        typedef Dual<double> result_type;
    };
    
    template<>
    struct promote_traits<Dual<double>, int> {
        typedef Dual<double> result_type;
    };
    
    template<>
    struct promote_traits<int, Dual<double> > {
        typedef Dual<double> result_type;
    };

    
    template <typename L, typename R>
    Dual<typename promote_traits<L, R>::type>
        operator +(const Dual<L>& x, const Dual<R>& y)
    {
        typedef typename promote_traits<L, R>::type result_type;
        return Dual<result_type>(x._value + y._value,
            x._derivative + y._derivative);
    }

    template <typename L, typename R>
    Dual<typename promote_traits<L, R>::type>
        operator -(const Dual<L>& x, const Dual<R>& y)
    {
        typedef typename promote_traits<L, R>::type result_type;
        return Dual<result_type>(x._value - y._value,
            x._derivative - y._derivative);
    }

    template <typename L, typename R>
    Dual<typename promote_traits<L, R>::type>
        operator *(const Dual<L>& x, const Dual<R>& y)
    {
        typedef typename promote_traits<L, R>::type result_type;
        return Dual<result_type>(x._value * y._value,
            x._value * y._derivative + x._derivative * y._value);
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
