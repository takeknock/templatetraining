template <class T>

T average(T* array, const int arraySize)
{
    T sum = 0;
    for (int i = 0; i < array.size(); ++i) {
       sum += array[i]; 
    }
    return sum / arraySize;
}


int main()
{
    const char* ca = "tese";
    //template<typename T> ave = template<typename T> average(ca, 4);
    const double d[2] = {12.5, 10.0};
    template<class T>;
    T ave = average(d, 4);


    return 0;
}


