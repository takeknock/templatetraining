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

        const Dual<T> operator +(const Dual<T>& r) const;
    
    private:
        T _a;
        T _b;
    };
    

//    template <typename R>
//    struct promote_traits {
//        typedef Dual<R> type;
//    };
//
//    template <>
//    struct promote_traits<Dual<double> > {
//        typedef Dual<double> type;
//    };
//
//    template <>
//    struct promote_traits<Dual<int> > {
//        typedef Dual<double> type;
//    };

    template <>
    const Dual<double> Dual<double>::operator+(const Dual<double>& y) const
    {
        Dual<double> result(this->_a + y._a, this->_b + y._b);
        return result;
    }

//    template <>
//    const promote_traits<Dual<double> >::type Dual<double>::operator+(const Dual<double>& y) const
//    {
//        promote_traits<Dual<double> >::type result(this->_a + y._a, this->_b + y._b);
//        return result;
//    }
//
//    template <>
//    const promote_traits<Dual<int> >::type Dual<double>::operator+(const Dual<int>& y) const
//    {
//        promote_traits<Dual<int> > result(this->_a + y._a, this->_b + y._b);
//        return result;
//    }

}// namespace dual {

#endif
