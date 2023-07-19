/*
 * A function template is automatically able to deduce their return type:
 *  template <typename T1, typename T2>
 *  auto add(T1 fir, T2 sec) -> decltype(fir + sec){
 *    return fir + sec;
 *  }
 * Note: the automatic return type deduction is typically used for function templates but can also be
 * applied to non-template function.
 *
 * Rules for C++11:
 *  - auto: introduces the synatx for the delayed return type.
 *  - auto: auto type deduction is based on the function template argument deduction. Function template 
 *    argument deduction (decays). So t means auto does not return the exact type but a decayed type 
 *    such as for template argument deduction.
 *  - decltype: declares the return type.
 *  - the alternative function syntax is obligatory.
 * Note: the C++ sytax for automatically deducing the return type breaks the crucial principle of 
 * software development: DRY. DRY stands for Don't Repeat Yourself.
 *
 * Automatic Return Type: C++14
 * A function template is automatically able to deduce their return type:
 *  template <typename T1, typename T>
 *  auto add(T1 fir, T2 sec){
 *    return fir + sec;
 *  }
 * In this case we have only one rule:
 *  - auto: introduces the syntax for delayed return type.
 * With the expression decltype(auto), auto uses the same rules to determine the type as decltype. This 
 * means, in particular, no decay takes place.
 * 
 * Both below declarations are identcal:
 *  decltype(expr) v = expr;
 *  decltype(auto) v = expr;
 *
 * The synatx also applies for the automatic return type of a function template:
 *  template <typename T1, typename T2>
 *  decltype(auto) add(T1 fir, T2 sec){
 *    return fir + sec;
 *  }
 * Note: when a function template has more than one return statements, all return statements must have
 * the same type.
*/
#include <iostream>
#include <typeinfo>

template <typename T1, typename T2>
auto add(T1 first, T2 second) ->decltype(first + second){
  return first + second;
}

int main(){
  std::cout << std::endl;

  std::cout << "add(1, 1): " << add(1, 1) << std::endl;
  std::cout << "typeid(add(1, 1)).name(): " << typeid(add(1, 1)).name() << std::endl;

  std::cout << std::endl;

  std::cout << "add(1, 2.1): " << add(1, 2.1) << std::endl;
  std::cout << "typeid(add(1, 2.1)).name(): " << typeid(add(1, 2.1)).name() << std::endl;

  std::cout << std::endl;
  
  std::cout << "add(1000LL, 5): " << add(1000LL, 5) << std::endl;
  std::cout << "typeid(add(1000LL, 5)).name(): " << typeid(add(1000LL, 5)).name() << std::endl;



  return 0;
}
