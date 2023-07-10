/*
 * Template arguments can, in general, automatically be deduced for function templates. The compiler 
 * deduces the template arguments for the function arguments. From the user's perspective, function 
 * templates feel like a functions.
 * Conversion:
 *  - The compiler uses simple converions for deducing the template arguments from the function 
 *    arguments.
 *  - The compiler removes const or volatile from the function arguments and converts C-arrays and
 *    functions to pointers.
 * Template agrument deduction from functon templates:
 *  template <typename T>
 *  void func(ParamType param);
 * In this case two datatypes were deduced: T and ParamType. ParamType can be:
 *  - reference or pointer;
 *  - universal reference (&&);
 *  - value (copy).
 *
 *  1. The parameter type is a reference or pointer:
 *     template <typename T>
 *     void func(T& param);
 *     // void func(T* param);
 *     func(expr);
 *      - T ignores reference or pointer.
 *      - Pattern matching on expr for T& or T.
 *  2. The parameter type is a universal reference (&&)
 *     template <typename T>
 *     void func(T&& param);
 *     func(expr);
 *      - expr is an lvalue: T and ParamType become lvalue references.
 *      - expr is an rvalue: T is deduced such as the ParamType is a reference.
 *  3. Parameter type us a value (copy)
 *     template <typename>
 *     void func(T param);
 *     func(expr);
 *      - expr is a reference: the reference (pointer) of the argument is ignored.
 *      - expr is const or volatile: const or volatile s ignored.
 *
 * Template Arguments in C++17
 * The constructor can deduce its template arguments from its function arguments.
 * Template Argument deduction for a constructor is available since C++17, but for function templates
 * since C++98.
 *  std::pair<int, double> myPair(2023, 1.23);
 *  std::pair myPair(2023, 1.23);
 * Many of the make_ functios such std::make_pair are not necessary anymore:
 *  auto myPair = std::make_pair(2023, 1.23);
 *
 * Argument Deduction 
 * The types of function arguments have to be exact, otherwise, no Conversion takes place.
 *  template <typename T>
 *  bool isSmaller(T fir, T sec){
 *    return fir < sec;
 *  }
 *
 *  isSmaller(1, 5LL); // Error: int != long long int
 *
 * Providing a second template parameter makes this example work.
 *  template <typename T, typename U>
 *  bool isSmaller(T fir, U sec){
 *    return fir < sec;
 *  }
 *
 *  isSmaller(1, 5LL); // Error: int != long long int
 *
 * Explicit Template Arguments
 * We have to use explicit template arguments in following scenarios:
 *  - if the template argument cannot be deduced from the function argument;
 *  - if a specific instance of a function template is needed.
 *  template <typename R, typename T, typename U>
 *  R add(T fir, U sec){
 *    return fir * sec;
 *  }
 *  add<long long int>(1000000, 1000000LL);
 * Note: Missing template arguments are automatically derived from the function arguments.
 *
 * Default Template Arguments
 * The default for template parameters can be specified for class templates and function templates. If a 
 * template parameter has a default parameter, all subsequent template parameters also need a default 
 * argument.
 *  template <typename T, typename Pred=std::less<T>>
 *  bool isSmaller(T fir, T sec, Pred pred = Pred()){
 *    return pred(fir, sec);
 *  }
*/
// Deduction of Template Arguments
#include <iostream>

template <typename T>
bool isSmaller(T fir, T sec){
  return fir < sec;
}

template <typename T, typename U>
bool isSmaller2(T fir, U sec){
  return fir <  sec;
}

template <typename R, typename T, typename U>
R add(T fir, U sec){
  return fir + sec;
}

int main(){
  std::cout << std::boolalpha << std::endl;

  std::cout << "isSmaller(1,2): " << isSmaller(1,2) << std::endl;
  // std::cout << "isSmaller(1,5LL): "  << isSmaller(1,5LL) << std::endl; // ERROR

  std::cout << "isSmaller<int>(1,5LL): " << isSmaller<int>(1,5LL) << std::endl;
  std::cout << "isSmaller<double>(1,5LL): " << isSmaller<double>(1,5LL) << std::endl;

  std::cout << std::endl;

  std::cout << "isSmaller2(1,5LL): "  << isSmaller2(1,5LL) << std::endl;

  std::cout << std::endl;

  std::cout << "add<long long int>(1000000,1000000): " << add<long long int>(1000000, 1000000) 
    << std::endl;
  std::cout << "add<double,double>(1000000,1000000): " << add<double,double>(1000000, 1000000) 
    << std::endl;
  std::cout << "add<double,double,float>(1000000,1000000): " 
    << add<double,double,float>(1000000, 1000000) << std::endl;


  return 0;
}
