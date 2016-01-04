#ifndef DUAL_DUAL_INCLUDED
#define DUAL_DUAL_INCLUDED

namespace dual {
    template <class T>
    class Dual {
    public:
        friend class DualTest;
        Dual()
        :_a(0.0), _b(0.0)
        {
        }

        Dual(T a, T b)
        :_a(a), _b(b)
        {
            
        }

        ~Dual()
        {
        }

        Dual<T> operator +(const Dual<T>& r);
    
    private:
        T _a;
        T _b;
    };
    

//    template <typename R>
//    struct promote_traits {
//        typedef R type;
//    };

//    template <>
//    struct promote_traits<Dual> {
//        typedef Dual type;
//    };

//    template <>
//    const promote_traits<Dual<double> > Dual<double>::operatorPlus(const Dual<double>& y)
//    {
//        promote_traits<Dual<double> >::type result(this->a + y._a, this->b + y._b);
//        return result;
//    }

    template <>
    Dual<double> Dual<double>::operator+(const Dual<double>& y)
    {
        Dual<double> result(this->_a + y._a, this->_b + y._b);
        return result;
    }
    
}// namespace dual {

#endif
