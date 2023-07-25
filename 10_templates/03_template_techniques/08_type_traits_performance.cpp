/*
 * The idea is quite straightforward and is used implementations of the Standard Template Library (STL).
 * If the elements of a container are simple enough, the algorithm of the STL like std::copy, std::fill,
 * or std::equal wil directly be applied on the memory area, Instead of using std::copy to copy the 
 * elements one by one, all is done in one step. Internally, C functions like memcmp, memset, memcpy, or 
 * memmove are used. The small difference between memcpy and memmove is that memmove can deal with 
 * overlapping memory areas.
 * The implementations of the algorithm std::copy, std::fill, or std::equal use a simple strategy. 
 * std::copy is lke a wrapper. This wrapper checks if the element is simple enough. If so, the wrapper 
 * will delegate the work to optimized copy function. If not, the general copy algorithm will be used.
 * This one copies each element after one another. To make the right decision, the function of the 
 * type-traits library will be used if the elements are simple enough.
*/
// std::fill assigns each element, in the range, a value
#include <cstring>
#include <chrono>
#include <iostream>
#include <type_traits>

namespace my {
  template <typename I, typename T, bool b>
  void fill_impl(I first, I last, const T& val, const std::integral_constant<bool, b>&){
    while (first != last) {
      *first = val;
      ++first;
    }
  }

  template <typename T>
  void fill_impl(T* first, T* last, const T& val, const std::true_type&){
    std::memset(first, val, last-first);
  }
  
  // Here we make the decision which implementation os my::fill_impl is applied. To use the optimized
  // variant, the elements should have a complier generated copy assignment operator
  // std::is_trivially_copy_assignable<T> and should be 1 byte large: sizeof(T) == 1. The function 
  // std::is_trivially_copy_assignable is part of the type-traits library. The first call 
  // my::fill(charArray1, charArray1 + arraySize, 1); has the last parameter 1, which is an int that has
  // a size of 4 bytes. That is why the test evaluates to false.
  template <class I, class T>
  inline void fill(I first, I last, const T& val){
    typedef std::integral_constant<bool, std::is_trivially_copy_assignable<T>::value &&
      (sizeof(T) == 1)> boolType;
    fill_impl(first, last, val, boolType());
  }

}

const int arraySize = 100000000;
char charArray1[arraySize]= {0,};
char charArray2[arraySize]= {0,};

int main(){
  std::cout << std::endl;

  auto begin= std::chrono::system_clock::now();
  my::fill(charArray1, charArray1 + arraySize,1);
  auto last=  std::chrono::system_clock::now() - begin;
  std::cout <<  "charArray1: " << std::chrono::duration<double>(last).count() << " seconds" << std::endl;

  begin= std::chrono::system_clock::now();
  my::fill(charArray2, charArray2 + arraySize, static_cast<char>(1));
  last=  std::chrono::system_clock::now() - begin;
  std::cout <<  "charArray2: " << std::chrono::duration<double>(last).count() << " seconds" << std::endl;

  std::cout << std::endl;

  return 0;
}
