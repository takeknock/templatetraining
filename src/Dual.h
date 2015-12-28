#ifndef DUAL_DUAL_INCLUDED
#define DUAL_DUAL_INCLUDED

namespace dual {
    template <class T>
    class Dual {
    public:
        friend class DualTest;
        Dual(T a, T b);
        ~Dual();
    
    private:
        T _a;
        T _b;
    };
    
    template <class T>   
    Dual::Dual(T a, T b)
    :_a(a), _b(b)
    {
    
    }
    
    Dual::~Dual()
    {
    
    }
    
}// namespace dual {

#endif
