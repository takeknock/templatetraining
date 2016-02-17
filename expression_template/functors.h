#ifndef FUNCTORS_H_INCLUDED
#define FUNCTORS_H_INCLUDED

// Dual系のものしか受け取れないようにするために、どの段階でdual_expressionをかますか？
namespace cp {
    template <typename X, typename Y>
    class scalar_plus {
    public:
        typedef promote_traits<X, Y>::result_type result_type;
        result_type operator()(const X& x, const Y& y)
        {
            return x + y;    
        }
        
    };

}

#endif // FUNCTORS_H_INCLUDED
