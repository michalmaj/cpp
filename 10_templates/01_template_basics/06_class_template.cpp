// Methods in Class Templates
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, int N>
class Array{
public:
    Array() = default;

    template<typename T2>
    Array<T, N>& operator=(const Array<T2, N>& arr){
        elem.clear();
        elem.insert(elem.begin(), arr.elem.begin(), arr.elem.end());
        return *this;
    }

    int getSize() const;

    std::vector<T> elem;
};

template <typename T, int N>
int Array<T, N>::getSize() const {
    return N;
}

int main(){
    std::cout << std::endl;

    Array<double, 10> doubleArray{};
    Array<int, 10> intArray{};

    doubleArray = intArray;

    Array<std::string, 10> strArray{};
    Array<int, 100> bigIntArray;

//    doubleArray = strArray; // ERROR: cannot convert 'const std::basic_string<char>' to 'double'
//    doubleArray = bigIntArray; // ERROR: no match for 'operator=' in 'doubleArray = bigIntArray'
    return 0;
}