/*
 * Use the function static_assert in combination with the function std::is_convertible to catch the
* erroneous instantiation at compile-time.
*/
#include <iostream>
#include <algorithm>
#include <vector>

#include <type_traits>
#include <concepts> // We can alos use concepts (since C++20)

template <typename T, int N>
class Array{
public:
  Array() = default;

  template <typename T2> 
  requires std::is_convertible_v<T, T2> // Commnet this line or line no 20
  Array<T, N>& operator=(const Array<T2, N>& arr){
    //static_assert(std::is_convertible<T2, T>::value, "Cannot convert source type to destination type!");
    elem.clear();
    elem.insert(elem.begin(), arr.elem.begin(), arr.elem.end());
    return *this;
  }

  int getSize() const;

  std::vector<T> elem;
};

template <typename T, int N>
int Array<T, N>::getSize() const{
  return N;
}

int main(){

  Array<double, 10> doubleArray{};
  Array<int, 10> intArray{};

  doubleArray= intArray;

  Array<std::string, 10> strArray{};
  Array<int, 100> bigIntArray{};

  doubleArray = strArray;

  return 0;
}
