#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace aliastraining {
    using namespace boost::numeric::ublas;
    template <typename T_class>
    void rand1Update(matrix<T_class>& A, const vector<T_class>& x)
    {
        for (int rowIndex = 0; rowIndex < A.size1(); ++rowIndex) {
            for (int columnIndex = 0; columnIndex < A.size2(); ++columnIndex) {
                A(rowIndex,columnIndex) += x(rowIndex) * x(columnIndex);
            }
        }
    }
} // namespace aliastraining



int main() {
    using namespace boost::numeric::ublas;
    matrix<double> mat_d(2,2);
    mat_d(0,0) = 1.0;
    mat_d(0,1) = 2.0;
    mat_d(1,0) = 3.0;
    mat_d(1,1) = 4.0;
    vector<double> vec_d(2);
    vec_d(0) = 5.0;
    vec_d(1) = 7.0;
    aliastraining::rand1Update(mat_d, vec_d);
    std::cout << mat_d << std::endl;
    return 0;
}

