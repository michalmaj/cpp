/*
 * Fold expression is a nice syntax to evaluate binary operators at compile-time. Fold expressions 
 * reduce parameter packs on binary opeartors.
 * C++11 provides support for parameter packs:
 *  bool all_14(){
 *    return true;
 *  }
 *  
 *  template <typename T, typename ... Ts>
 *  bool all_14(T t, Ts ... ts){
 *    return t && all_14(ts ...);
 *  }
 *
 * C++17 provides support for fold expression.
 *  template <typename ... Args>
 *  bool all_17(Args ... args){
 *    return (... && args)
 *  }
 *  
 *  bool val == all_14(true, true, true, false)
 *           == all_17(true, true, true, false
 *           == ((true && true) && true) && false
 *           == false;
 *
 * Two variations:
 *  - The fold expression either has or does not have an initial value.
 *  - The parameter pack will be processed from left or right.
 *
 * C++17 supports the following 32 operators in fold expressions:
 * + - * / % ^ & | = < > << >> += -= *= /= %= ^= &= |= <<= >>= == != <= >= && || , .* ->*
 * Operators with their default values:
 *  Operator              Symbol          Default Value 
 *  Logical AND           &&              true 
 *  Logical OR            ||              false 
 *  Comma operator        ,               vod()
 *
 * For binary opeartors that have no default value, we have to provide an initial value. For binary 
 * operators that have a default value, we can specify an initial value.
 * If the ellipsis stands left of the parameter pack, the parameter pack will be processed from the 
 * left. The same holds for right. This is also true if we provide an initial value.
 * The following table shows the four variations and their Haskell pendants. The C++17 standard requires
 * that fold expressions with initial value use the same binary operator op.
 * C++17 templates support Haskell fold* variants at compile-time, i.e., fold1, foldl1, foldr, foldr1:
 *  Fold Expressions              Haskell                 Description
 *  ... op pack                   fold1 op list           Process from left with operator op.
 *  pack op ...                   foldr1 op list          Process from right with operator op.
 *  init op ... op pack           foldl op init list      Process from left with operator op and initial
 *                                                        value init.
 *  pack op ... op init           foldr op init list      Process from right with operator op and 
 *                                                        initial value init.
 *
 * The C++ and Haskell variations differ in two points. The C++ version uses the default value as the 
 * initial value while the Haskell version uses the first element as the initial value. The C++ version 
 * processes the parameter pack at compile-time and the Haskell version, at the run-time.
*/
#include <iostream>

// all function returns true only if all the values passed to it are true, else false because we're 
// using && as an operator.
template <typename ... Args>
bool all(Args ... args) { return (... && args); }

// any function returns true if any passed value is true, else false because we're using || as an 
// operator.
template <typename ... Args>
bool any(Args ... args) { return (... || args); }

// none function returns true only f all the passed parameters are false because we're using || operator
// with not and it will invert the result.
template <typename ... Args>
bool none(Args ... args) { return not(... || args); }

int main(){

  std::cout << std::boolalpha << std::endl;

  std::cout << "all(true): " << all(true) << std::endl; // t
  std::cout << "any(true): " << any(true) << std::endl; // t
  std::cout << "none(true): " << none(true) << std::endl; // f

  std::cout << std::endl;

  std::cout << "all(true, true, true, false): " << all(true, true, true, false) << std::endl; // f
  std::cout << "any(true, true, true, false): " << any(true, true, true, false) << std::endl; // t
  std::cout << "none(true, true, true, false): " << none(true, true, true, false) << std::endl; // f
  
  std::cout << std::endl;
  
  std::cout << "all(false, false, false, false): " << all(false, false, false, false) << std::endl; // f
  std::cout << "any(false, false, false, false): " << any(false, false, false, false) << std::endl; // f
  std::cout << "none(false, false, false, false): " << none(false, false, false, false) << std::endl;// t


  return 0;
}
