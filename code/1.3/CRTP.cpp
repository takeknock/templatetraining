// all subtypes naively must have all menber functions.
// The solution for this problem is CRTP (the Barton and Nackman Trick).
// CRTP also solves the ambiguity of deriving.

template <typename T>
class Vec {
public:
    Vec()
    {
    }


};

template <typename Derived>
class VectorExpression {
    const Derived& operator()() const
    {
        //自己への参照を子クラスへの参照へとstatic_castする親クラスを定義
        return static_cast<const Derived&>(*this);
    }
};


template <typename A, typename B>
class VecPlus : public VectorExpression<VecPlus<A, B> >{
public:
    VecPlus(const A& a, const B& b)
    :_a(a), _b(b)
    {
    }

    const_reference operator()(size_type i) const
    {
        return _a(i)+_b(i);
    }

    VecPlus<A, B> operator+(
        const VectorExpression<A>& a, const VectorExpression<B>& b)
    {
        return VecPlus<A, B>(a, b);
    }

private:
    const A& _a;
    const B& _b;
};

int main() 
{
    const std::vector a, b, c;
    const std::size_t i = 42;
    const auto y = a + b + c;
    const Vec::value_type yi = y(i);
    return 0;
}


