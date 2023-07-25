/*
 * Problem Statement 
 * Get used to the many functions of the type traits library.
 * The objective of this exercise is to get familiar with the type-traits library. What we want to 
 * achieve here is to modify an int type by doing a, b, c and d.
 *  - Modify an int type at compile-time.
 *  - Add const to it.
 *  - Remove const from it.
 *  - Compare it with a const int.
*/
#include <iostream>
#include <type_traits>

int main() {
  // Write different functions of type traits here
  std::cout << std::boolalpha << std::endl;

  std::cout << "std::is_const<std::add_const<int>::type>::value: " <<
    std::is_const<std::add_const<int>::type>::value << std::endl;
  std::cout << "std::is_const<std::remove_const<const int>::type>::value: " <<
    std::is_const<std::remove_const<const int>::type>::value << std::endl;

  std::cout << std::endl;

  typedef std::add_const<int>::type myConstInt;
  std::cout << "std::is_const<myConstInt>::value: " <<
    std::is_const<myConstInt>::value << std::endl;
  typedef const int myConstInt2;
  std::cout << "std::is_same<myConstInt, myConstInt2>::value: " <<
    std::is_same<myConstInt, myConstInt2>::value << std::endl;

  std::cout << std::endl;

  int fir = 1;
  int& refFir1 = fir;
  using refToIntType = typename std::add_lvalue_reference<int>::type;
  refToIntType refFir2 = fir;

  std::cout << "(fir, refFi1r, refFir2): "  << "(" << fir << ", " << refFir1 << ", " << refFir2 << ")" 
    << std::endl;

  fir = 2;

  std::cout << "(fir, refFi1r, refFir2): "  << "(" << fir << ", " << refFir1 << ", " << refFir2 << ")" 
    << std::endl;

  return 0;
}
