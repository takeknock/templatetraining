#ifndef TYPE_TRAITS_H_INCLUDED
#define TYPE_TRAITS_H_INCLUDED
#include "Dual.h"

template<typename l, typename r>
struct promote_traits {
    typedef l result_type;
};


template<>
struct promote_traits<int, double> {
    typedef double result_type;

};

template<>
struct promote_traits<double, dual::Dual> {
    typedef Dual result_type;
};

template<>
struct promote_traits<dual::Dual, int> {
    typedef Dual result_type;
};
#endif // TYPE_TRAITS_H_INCLUDED
