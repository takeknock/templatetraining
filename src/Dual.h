#ifndef DUAL_INCLUDED
#define DUAL_INCLUDED

namespace dual {
    template <typename T>
    class Dual {
    public:
        Dual()
        :_a(0), _b(0)
        {
        }

        Dual(T a, T b)
        :_a(a), _b(b)
        {
            
        }

        ~Dual()
        {
        }

    
    private:
        T _a;
        T _b;
    };
    //const Dual<T> operator +(const Dual<T>& r) const;
    

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

//    template <>
//    const Dual<double> Dual<double>::operator+(const Dual<double>& y) const
//    {
//        Dual<double> result(this->_a + y._a, this->_b + y._b);
//        return result;
//    }

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
