/*
 * Problem Statement
 * Implement the metafunction to calculate the factorial of a number.
*/
#include <iostream>

// The Factorial function calls itself recursively by storing the result of each iteration in value. For 
// the base case, the result is multiplied by 1 in line 17 and the answer is stored in value.
template <int N> 
struct Factorial{
  // Implement the functionality to run the code in the main
  static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<1>{
  static const int value = 1;
};

int main(){
  // Uncomment the given code after implementing the Factorial function
  std::cout << Factorial<6>::value << std::endl;
}

