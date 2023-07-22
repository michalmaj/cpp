/*
 * Type-traits enable type checks, type comparisons, and type modifications at compile-time.
 * Below are some applications of template metaprogramming:
 *  - Programming at compile-time.
 *  - Programming with types and values.
 *  - Compiler translates the templates and transform it in C++ source code.
 * We need to add a type_traits library in the header to enable all the functions present in the library.
 *  #include <type_traits>
 *
 * Type-Traits: Goals
 * If we look carefully, we'll see that type-traits have a significant optimilization potential. In the 
 * first step, type-traits help to analyze the code at compile-time and in second step, to optimize the 
 * code based on that analysis. How is that possible? Depending on the type of variable, a faster variant
 * of an algorithm will be chosen.
 * Optimization:
 *  - Code that optimizes itself. Depending on the type of a variable another code will be chosen.
 *  - Optimized version of std::copy, std::fill, or std::equal is used so that algorithms can work on 
 *    memory blocks.
 *  - The Optimized version of operations happens on all the elements in a container in one step and not
 *    on each element individually.
 * Correctness:
 *  - Type checks will be performed at compile-time.
 *  - Type information, together with statc_assert, defines the requirements for the code.
 *  - With the concepts in C++20, the correctness aspect of the type-traits becomes less important.
 *
 * Type Checks 
 * C++14 has 14 primary type categories. They are complete and orthogonal. This means, that each type is 
 * a member of exactly one type category. The check for the type categories is independent of the type 
 * qualifiers const or volatile:
 *  template <class T> struct is_void;
 *  template <class T> struct is_integral;
 *  template <class T> struct is_floating_point;
 *  template <class T> struct is_array;
 *  template <class T> struct is_pointer;
 *  template <class T> struct is_reference;
 *  template <class T> struct is_member_object_pointer;
 *  template <class T> struct is_member_function_pointer;
 *  template <class T> struct is_enum;
 *  template <class T> struct is_union;
 *  template <class T> struct is_class;
 *  template <class T> struct is_function;
 *  template <class T> struct is_lvalue_reference;
 *  template <class T> struct is_rvalue_reference;
 * We can divide the type-traits into smaller sets for simplicity.
 *  - Primary type category (::value)
 *    std::is_pointer<T>,
 *    std::is_integral<T>,
 *    std::is_floating_point<T>
 *  - Composed type category (::value)
 *    std::is_arithmetic<T>,
 *    std::is_object<T>
 *  - Type comparisons (::value)
 *    std::is_same<T, U>,
 *    std::is_base_of<Base, Derived>,
 *    std::is_convertible<From, To>
 *  - Type transformation (::type)
 *    std::add_const<T>,
 *    std::remove<reference>,
 *    std::make_signed<T>,
 *    std::make_unsigned<T>
 *  - Others (::type)
 *    std::enable_if<bool, T>,
 *    std::conditional<bool, T, F>
 *    std::common_type<T1, T2, T3, ... >
 * The above-mentioned functions, from the type-traits, give only a rough idea of their power:
 * https://en.cppreference.com/w/cpp/header/type_traits
*/
#include <iostream>
#include <string>
#include <type_traits>

namespace rgr{
  template <typename T, typename U>
  struct is_same: std::false_type {};
  
  template <typename T>
  struct is_same<T, T>: std::true_type {};

  template <typename T>
  struct remove_const{
    typedef T type;
  };
  
  template <typename T>
  struct remove_const<const T>{
    typedef T type;
  };

}

int main(){
  std::cout << std::boolalpha << std::endl;

  std::cout << std::is_same<int, std::remove_const<const int>::type>::value << std::endl;
  std::cout << rgr::is_same<int, rgr::remove_const<const int>::type>::value << std::endl;

  typedef rgr::remove_const<double>::type myDouble;
  std::cout << rgr::is_same<double, myDouble>::value << std::endl;

  typedef rgr::remove_const<const std::string>::type myString;
  std::cout << rgr::is_same<std::string, myString>::value << std::endl;

  typedef rgr::remove_const<std::add_const<int>::type>::type myInt;
  std::cout << rgr::is_same<int, myInt>::value << std::endl;



  return 0;
}
