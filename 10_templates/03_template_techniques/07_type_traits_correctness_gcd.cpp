/*
 * The reason we use type-traits is correctness and optimization. Let's start with correctness. The idea 
 * is to implement generic gcd algorithms, step by  step, to make it more type-safe with the help of the 
 * type-traits library.
*/
#include <iostream>
#include <type_traits>
#include <typeinfo>

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

// But what about the second issue. THe gcd algorithm should accept arguments of a different type.
// gcd - The Third (The Smaller Type)
// A good choice for the return type is to use the smaller of both types. Therefore, we need a ternary 
// operator at compile-time. Thanks to the type-traits library, we have it. The ternary function 
// std::conditional operates on types and not on values. That's because we apply the function at 
// compile-time. So, we have to feed std::conditional with the right constant expression and we are done.
// std::conditional<(sizeof(T1) < sizeof(T2)), T1, T2>::type will return, at compile-time, T1 if T1 is 
// smaller than T2; it will return T2 if T2 is not smaller than T1.
template <typename T1, typename T2>
typename std::conditional<(sizeof(T1) < sizeof(T2)), T1, T2>::type gcd3(T1 a, T2 b){
  static_assert(std::is_integral<T1>::value, "T1 should be integral!\n");
  static_assert(std::is_integral<T2>::value, "T2 should be integral!\n");
  if(b == 0) return a;
  else return gcd3(b, a & b);
}

// gcd - The Third (The Common Type)
// Often it is not necessary to determine the smaller type at compile-time but to determine the type to 
// which all types can implicitly be converted to. std::common_type can handle an arbitrary number of 
// template arguments.
// The only difference to the above implementation is that std::common_type, which determines the while
// return type. With the argument types int and int we get int; with the argument types int and long int
// we get long int, and with int and long long int we get long long int.
template <typename T1, typename T2>
typename std::common_type<T1, T2>::type gcd4(T1 a, T2 b){
  static_assert(std::is_integral<T1>::value, "T1 should be an integral type!\n");
  static_assert(std::is_integral<T2>::value, "T2 should be an integral type!\n");
  if(b == 0) return a;
  else return gcd4(b, a % b);
}

// gcd - The Fourth
// std::enable_if from 

int main(){
  std::cout << "gcd - The First:\n";
  std::cout << gcd1(100, 10) << std::endl;  // 10
  std::cout << gcd1(100, 33) << std::endl;  // 1
  std::cout << gcd1(100, 0) << std::endl;   // 100
  //std::cout << gcd1(3.5, 4.0) << std::endl; // ERROR: can't use modulo operator on double variables.
  //std::cout << gcd1("100", "10") << std::endl;  // ERROR: can't use modulo operator on strings.
  //std::cout << gcd1(100, 10L) << std::endl;  // ERROR: deduced conflicting types for parameter ‘T’.
  
  std::cout << std::endl;

  std::cout << "gcd - The Second:\n";
  //std::cout << gcd2(3.5, 4.0) << std::endl; // ERROR: but we have better output.
  //std::cout << gcd2("100", "10") << std::endl; // ERROR: but we have better output.
  
  std::cout << std::endl;

  std::cout << "gcd - The Third (The Smaller Type):\n";
  std::cout << gcd3(100,10LL) << std::endl;
  auto res = gcd3(100,10LL);
  std::conditional<(sizeof(long long)<sizeof(long)), long long, long>::type res2=gcd3(100LL,10L);
  std::cout << typeid(res).name() << std::endl;  // i 
  std::cout << typeid(res2).name() << std::endl; // l 

  std::cout << std::endl;
  
  std::cout << "gcd - The Third (The Smaller Type):\n";
  std::cout << typeid(gcd4(100, 10)).name() << std::endl;  // i 
  std::cout << typeid(gcd4(100, 10L)).name() << std::endl;  // l 
  std::cout << typeid(gcd4(100, 10LL)).name() << std::endl;  // x


  return 0;
}
