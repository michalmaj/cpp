/*
 * A function template will be defined by placing the keyword template followed by type or non-type
 * parameters in front of a concrete function. After that, we replace the concrete types or non-types 
 * with the type or non-type parameters in the function.
 *  - The keyword class or typename declares the parameters.
 *  - The name T is usually used for the first parameter.
 *  - The parameters can be used in the body of the function.
 *
 * Passing Arguments in Function Templates:
 * In the given example, we'll look at how we can call the initialized variables with our tempalte. The
 * function arguments x and y in the function xchg must have the same type:
 *  template <typename T>
 *  void xchg(T& x, T& y)
 * By providing two type parameters the types of arguments can be different:
 *  template <typename T1, typename T2>
 *  void add(T1& x, T2& y)
 * Then we have a non-type template parameter N:
 *  template <int N>
 *  int nTimes(int n)
 *
 * Instantiation
 * The process of substitutiing the template parameters for the tempate arguments is called template
 * instantiation.
 * The compiler:
 *  - Automatically creates an instance of the function template.
 *  - Will automatically create a function template if the template parameters can be derived from the
 *    function arguments.
 * If the compiler cannot deduce the template arguments from the function arguments,we will have to 
 * specify them explicitly.
 *
 * Overloading
 * Function templates can be overloaded.
 * The following rules hold:
 *  1. Templates do not support an automatic type conversion.
 *  2. If a free function is better or equally as good as a function template that already exists, the
 *      free function can be used.
 *  3. We can explicitly specify the type of the function template:
 *     func<type>(...)
 *  4. We can specify that we are only interested in a specific instantiation of a function template:
 *     func<>(...)
*/
#include <iostream>
#include <string>
#include <vector>

// Two function templates: xchg and nTmes.
// First function swaps the values passed as arguments.
template <typename T>
void xchg(T& x, T& y){
  T t = x;
  x = y;
  y = t;
}

// The only non-type, we use in N n the function templates nTimes.
// Ths function returns the N times of the number passed n.
template <int N>
int nTimes(int n){
  return N * n;
}

int main(){
  std::cout << std::endl;

  bool t = true;
  bool f = false;
  std::cout << "(t, f): (" << t << ", " << f << ")\n";
  xchg(t, f);
  std::cout << "(t, f): (" << t << ", " << f << ")\n";

  std::cout << std::endl;

  int int2011 = 2011;
  int int2014 = 2014;
  std::cout << "(int2011, int2014):  (" << int2011 << ", " << int2014 << ") "<< std::endl;
  xchg(int2011, int2014);
  std::cout << "(int2011, int2014):  (" << int2011 << ", " << int2014 << ") "<< std::endl;

  std::cout << std::endl;

  std::string first{"first"};
  std::string second{"second"};
  std::cout << "(first, second):  (" << first << ", " << second << ") "<< std::endl;
  xchg(first, second);
  std::cout << "(first, second):  (" << first << ", " << second << ") "<< std::endl;

  std::cout << std::endl;
  std::vector<int> intVec1{1, 2, 3, 4, 5};
  std::vector<int> intVec2{5, 4, 3, 2, 1};

  std::cout << "vec1: ";
  for (auto v: intVec1)std::cout  << v << " ";
  std::cout << "\nvec2: ";
  for (auto v: intVec2)std::cout << v << " ";
  std::cout << std::endl;
  xchg(intVec1, intVec2);

  std::cout << "vec1: ";
  for (auto v: intVec1)std::cout  << v << " ";
  std::cout << "\nvec2: ";
  for (auto v: intVec2)std::cout << v << " ";
  std::cout << std::endl;


  std::cout << "\n\n";

  std::cout << "nTimes<5>(10): " << nTimes<5>(10) << std::endl;
  std::cout << "nTimes<10>(5): " << nTimes<10>(5) << std::endl;
  return 0;
}
