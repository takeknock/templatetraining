#include <boost/numeric/ublas.hpp>

namespace tt {
    using namespace boost::numeric::ublas;
    tempate<class T1, class T2>
    vector<double> operator+(vector<T1>&, vector<T2>&); // なぜconst参照じゃない？

    
    template<class T1, class T2>
    struct promote_trait {

    };

    #define DECLARE_PROMOTE(A, B, C)
        template<> struct promote_trait<A, B> {
            typedef C T_promote;
        };

    DECLARE_PROMOTE(int, char, int);
    DECLARE_PROMOTE(int, float, float);
    DECLARE_PROMOTE(float, complex<float>, complex<float>);

    template<class T1, class T2>



} // namespace tt {
