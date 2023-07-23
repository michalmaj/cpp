/*
 * The reason we use type-traits is correctness and optimization. Let's start with correctness. The idea 
 * is to implement generic gcd algorithms, step by  step, to make it more type-safe with the help of the 
 * type-traits library.
*/
#include <iostream>

// gcd - The First
// Our starting point is the euclid algorithm to calculate the greatest common divisor of two numbers.
// This function has two serious issues:
// 1. It is too generic. The function template accepts doubles and strings. But it makes no sense to 
//    determine the gcd of both data types.
// 2. We depend on one type parameter T. There in no conversion for type parameters. Theresore, the 
//    instantiation of gcd with an int and long type fails.
template <typename T>
T gcd1(T a, T b){
  if(b == 0) return a;
  else return gcd1(b, a % b);
}

// gcd - The Second
// The static_assert operator and the predicate std::is_integral<T>::value will help us to check at 
// compile-time whether T is an integral type.
// We will solve the first issue of the gcd algorithm. The compilation will not fail by accident because 
// the assertion will not hold ture.The difference is that we now get an extra error message and not a 
// cryptic output of a failed template.
template <typename T>
T gcd2(T a, T b){
  static_assert(std::is_integral<T>::value, "T should be integral type!\n");
  if(b == 0) return a;
  else return gcd2(b, a % b);
}


int main(){
  std::cout << gcd1(100, 10) << std::endl;  // 10
  std::cout << gcd1(100, 33) << std::endl;  // 1
  std::cout << gcd1(100, 0) << std::endl;   // 100
  //std::cout << gcd1(3.5, 4.0) << std::endl; // ERROR: can't use modulo operator on double variables.
  //std::cout << gcd1("100", "10") << std::endl;  // ERROR: can't use modulo operator on strings.
  //std::cout << gcd1(100, 10L) << std::endl;  // ERROR: deduced conflicting types for parameter ‘T’.
  
  std::cout << std::endl;

  //std::cout << gcd2(3.5, 4.0) << std::endl; // ERROR: but we have better output.
  //std::cout << gcd2("100", "10") << std::endl; // ERROR: but we have better output.



  return 0;
}
