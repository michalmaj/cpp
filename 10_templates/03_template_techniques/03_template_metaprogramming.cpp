/*
 * Template metaprogramming is Turing-complete and can, therefore, be used to solve any computional 
 * problem. Of course, Turing-complete holds only in theory for template metaprogramming because the 
 * recursion depth (at least 1024 with C++11) and the length of the names which are generated duriing 
 * template instantiation provide some limitations.
 *
 * Calculating at Compile-Time
 * The Factorial program is the Hello World of template metaprogramming:
 *  template <int N>
 *  struct Factorial{
 *    static int const value = N * Factorial<N-1>::value;
 *  };
 *
 *  template <>
 *  struct Factorial<1>{
 *    static int const value = 1;
 *  };
 *
 *  std::cout << Factorial<5>::value << std::endl;
 *  std::cout << 120 << std::endl;
 * The call Factorial<5>::value causes the instantiation of the primary or general template. During this 
 * instantiation, Factorial<4>::value will be instantiated. This recursion will end if the fully 
 * specialized class template Factorial<1> kicks in as the boundary condition.
 *
 * Type Manipulations 
 * Manipulating types at compile-time is typically for template metaprogramming:
 *  template <typename T>
 *  struct RemoveConst{
 *    typedef T type;
 *  };
 *
 *  template <typename T>
 *  struct RemoveConst<const T>{
 *    typedef T type;
 *  };
 *
 *  int main(){
 *    std::is_same<int, RemoveConst<int>::type>::value; // true
 *    std::is_same<int, RemoveConst<const int>::type>::value; // true
 *  }
 * The code, we have defined the class template RemoveConst in two versions. We have implemented 
 * RemoveConst the way std::remove_const is probaly implemented in the type-traits library.
 * std::is_same from the type-traits library helps us to decide at compile-time if both types are the 
 * same. In case of RemoveConst<int>, the first or general class template kicks in. In case of
 * RemoveConst<const int>, the partial specialization for const T applies. The key observation is that
 * both templates return the underlying type, therefore, the constness is removed.
 * This kind of technique, which is heavily used in the type-traits library, is a compile-time if on 
 * types.
 *
 * Metadata and Metafunctions
 * At compile-time, we speak about metadata and metafunctions instead of data and functions:
 *  - Metadata: Types and intergral types that are used in metafunctions.
 *  - Metafunctions: Functons that are executed at compile-time. Class templates are used to implement 
 *    metafunctions.
 *  - Return their value by ::value 
 *      template <>
 *      struct Factorial<1>{
 *        static const int value = 1;
 *      };
 *  - Return their type by ::type
 *      template <typename T>
 *      struct RemoveConst<const T>{
 *        typedef T type;
 *      };
 *
 * Functions vs Metafunctions
 *  Characteristics                 Functons                    Metafunctions
 *  Call                            power(2,10)                 Power<2,10>::value
 *  Execution Time                  Runtime                     Compile-Time
 *  Arguments                       Function arguments          Template arguments
 *  Arguments and return value      Arbitrary values            Types, non-type and templates
 *  Implementation                  Callable                    Class template 
 *  Data                            Mutable                     Immutable
 *  Modification                    Data can be modified        New data are created
 *  State                           Has state                   Has no state
 * What does the table above mean for a concrete function and a concrete metafunction:
 *  int power(int m, int n)             template <int m, int n>
 *  {                                   struct Power
 *    int r = 1;                        {
 *    for(int k=1; k<=n;++k){             static const int value = m * Power<m, n-1>::value;
 *      r *= m;                         };
 *    }                                 
 *    return r;                         template <int m>
 *  }                                   struct Power<m, 0>
 *                                      {
 *                                        static const int value = 1;
 *                                      };
 * Function arguments go into round() braces and template arguments go into sharp <> braces.
 *  int main(){
 *    std::cout << power(2, 10) << std::endl;
 *    std::cout << Power<2, 10>::value << std::endl;
 *  }
 *
 * Pure Functional Sublanguage
 * Template metaprogramming is:
 *  - an embedded pure functional language in the imperative language C++.
 *  - Turing-complete, that means all can be calculated what is calculable.
 *  - an intellectual playground for C++ experts.
 *  - the foundation for many boost libraries.
*/
// Templat Type Manipulation 
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

  std::cout << "std::is_same<int, RemoveConst<int>::type>::value: " << 
    std::is_same<int, RemoveConst<int>::type>::value << std::endl;
  std::cout << "std::is_same<int, RemoveConst<const int>::type>::value: " << 
    std::is_same<int, RemoveConst<const int>::type>::value << std::endl;
    
  std::cout << std::endl;

  return 0;
}
