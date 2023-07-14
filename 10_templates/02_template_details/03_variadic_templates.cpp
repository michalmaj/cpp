/*
 * A variadic template is a template that can has an arbitrary number of parameters:
 *  template <typename ... Args>
 *  void variadicTemplate(Args ... args){. . . .}
 * Parameter pack:
 * A template parameter pack is a template parameter that accepts zero or more template arguments 
 * (non-types, types, or templates). A function parameter pack is a function parameter that accepts zero
 * or more function arguments:
 *  - By using the ellipse (...), Args or args becomes a parameter pack,
 *  - Args is a template parameter packl args is a function parameter pack.
 *  - Parameter packs can only be packed and unpacked.
 *  - If the ellipsis is left from Args, the parameter pack will be packed and if the ellipse is right
 *    from Args, the parameter pack will be unpack.
 * Note: the compiler can automatically deduce the template arguments in case of a function template.
 * For example, the following classes/functions in STL extensively use variadic templates. Variadic 
 * Templates often used in the Standard Template Library: sizeof, std::tuple, std::thread, std::lock,
 * std::make_unique etc.
 * The usage of parameter packs obeys a typical pattern for class templates:
 *  - Perform an operaton on the first element of the parameter pack and recursively invoke the operation
 *    on the remaining elements.
 *  - The recursion ends after a finite number of steps.
 *  - The boundary condition is typically a fully specialized template.
 *
 *  template<>
 *  struct Mult<>{ .... }
 *  template<int i, int ... tail>
 *  struct Mult<i, tail ...> { .... }
*/
#include <iostream>

// In the below example, we will use printSize function, which prints the number of elements (of any 
// type) passed as arguments. It detetecs the number of elements on compile-time using the sizeof 
// operator, and in case of an empty argument list, it return 0.
template <typename ... Args>
int printSize(Args ... args){
  return sizeof ... (args);
}

// There is a struct defined as Mult which takes arguments of integer type and return their product. If 
// there is no arguments passed, then it returns 1 which is the neutral element for multiplication. The 
// result is stored the value in the fully specialized template.
// The primary template is never used and must, therefore, never be defined.
template<int ...>
struct Mult;

// Fully specialized template
template<>
struct Mult<>{
  static const int value = 1;
};

// The partial specialization.
template<int i, int ... tail>
struct Mult<i, tail ...>{
  // Star the recursion.
  static const int value = i * Mult<tail ...>::value;
};


int main(){
  std::cout << "printSize(): " << printSize() << std::endl;
  std::cout << R"(printSize("template"", 2023, true): )" << printSize("template", 2023, true) << "\n";
  std::cout << "printSize(1, 2.5, 4, 5, 10): " << printSize(1, 2.5, 4, 5, 10) << std::endl;

  std::cout << std::endl;

  std::cout << "Mult<10>::value: " << Mult<10>::value << std::endl;
  std::cout << "Mult<10, 10, 10>::value: " << Mult<10, 10, 10>::value << std::endl;
  std::cout << "Mult<1, 2, 3, 4, 5>::value: " << Mult<1, 2, 3, 4, 5>::value << std::endl;


  return 0;
}
