#ifndef TYPE_TRAITS_H_INCLUDED
#define TYPE_TRAITS_H_INCLUDED

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
struct promote_traits<double, dual::Dual<double> > {
    typedef dual::Dual<double> result_type;
};

template<>
struct promote_traits<dual::Dual<double>, double> {
    typedef dual::Dual<double> result_type;
};

template<>
struct promote_traits<dual::Dual<double>, int> {
    typedef dual::Dual<double> result_type;
};

template<>
struct promote_traits<int, dual::Dual<double> > {
    typedef dual::Dual<double> result_type;
};
#endif // TYPE_TRAITS_H_INCLUDED
