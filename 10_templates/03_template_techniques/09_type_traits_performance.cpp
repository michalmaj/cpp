/*
 * Template Type Manipulation
*/
#include <iostream>
#include <type_traits>

template <typename T>
struct RemoveConst{
  typedef T type;
};

template <typename T>
struct RemoveConst<const T>{
  typedef T type;
};

int main(){
  std::cout << std::boolalpha << std::endl;

  // The code below uses the function std::is_same from the type-traits library. std::is_same compares
  // the type passed in the function and the type given in the function defined by us, and it returns 
  // true only when both types are the same.
  std::cout << "std::is_same<int, RemoveConst<int>::type>::value: " << 
    std::is_same<int, RemoveConst<int>::type>::value << std::endl;
  std::cout << "std::is_same<int, RemoveConst<const int>::type>::value: " << 
    std::is_same<int, RemoveConst<const int>::type>::value << std::endl;
    
  std::cout << std::endl;

  return 0;
}
