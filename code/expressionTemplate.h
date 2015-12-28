template <class L, class R>
class Plus {
    const L& _l;
    const R& _r;
    
public:
    Plus(const L& l, const R& r)
    : _l(l), _r(r)
    {
        
    }

    float operator[](std::size_t i) const
    {
        return _l[i] + _r[i];
    }
};

inline Plus<L, R> operator +(const L& l, const R& r)
{
    return Plus<L, R>(l, r);
}
