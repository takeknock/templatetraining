#include <iostream>

namespace tt {
//    template <class T> 
//    T average(const T* array, const int numElement)
//    {
//        T sum = 0;
//        for (int i = 0; i < numElement; ++i) {
//           sum += array[i]; 
//        }
//        return sum / numElement;
//    }
    
    template <class T>
    struct float_trait {
        typedef T T_float;
    };
    
    template<>
    struct float_trait<int> { // from
        typedef double T_float; // to
    };

    template<>
    struct float_trait<char> { // from
        typedef double T_float; // to: double型をT_floatと表現
    };


    template <class T> 
    typename float_trait<T>::T_float average(const T* array, const int numElement)
    {
        typename float_trait<T>::T_float sum = 0;
        for (int i = 0; i < numElement; ++i) {
           sum += array[i]; 
        }
        return sum / numElement;
    }
}    //namespace tt
    
int main()
{
    const char* ca = "tese";
    double ave1 = tt::average(ca, 4);
    double d[2];
    d[0] = 2.0;
    d[1] = 4.0;
    double ave = tt::average(d, 2);

    std::cout << ave1 << std::endl;
    //std::cout << &ave1 << std::endl;
    std::cout << ave << std::endl;
    //std::cout << &ave << std::endl;

    return 0;
}
    
