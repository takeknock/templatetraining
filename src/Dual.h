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
    
    private:
        T _a;
        T _b;
    };
    
//    template <typename L, typename R>
//    promote_traits<L, R> Dual::operator +(const L& x, const R& y)
//    {
//        return promote_traits<L, R>(x._a + y._a, x._b + y.b);
//    }
    
}// namespace dual {

#endif
