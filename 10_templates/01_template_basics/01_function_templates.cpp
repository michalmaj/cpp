/*
 * Function Templates
 * A function template will be defined by placing the keyword template followed by type or non-type parameters in front
 * of a concrete function. After that, we replace the concrete types or non-types with the type or non-type parameters
 * in the function:
 *  - The keyword class or typename declares the parameters.
 *  - The name T is usually used for the first parameter.
 *  - The parameters can be used in the body of the function.
 *
 * Passing Arguments in Function Templates
 * In the given code snippet, we'll look at how we can call the initialized variables with our template. The function
 * arguments x and y in the function xchg must have the same type. By providing two type parameters, the types of
 * arguments can be different. In last function we see a non-type template parameter N.
 *  template <typename T>
 *  void xchg(T& x, T& y){...
 *
 *  template <typename T, typename T1>
 *  void add(T& x, T1& y){...
 *
 *  template <int N>
 *  int nTimes(int n){...
 *
 * Instantiation
 * The process of substituting the template parameters for the template arguments is called template instantiation.
 * The compiler:
 *  - Automatically creates an instance of the function template.
 *  - Will automatically create a function template if the template parameters can be derived from the function
 *    arguments.
 * If the compiler cannot deduce the template arguments from the function arguments, we'll have to specify them
 * explicitly.
 *  template <typename T>
 *  void xchg(T& x, T& y{...
 *
 *  int a, b;
 *  xchg(a, b);
 *
 *  template <int N>
 *  int nTimes(int n){...
 *
 *  int n = 5;
 *  nTimes<10>(n);
 *
 * Overloading
 * Function templates can be overloaded.
 * The following rules hold:
 *  1. Templates do not support an automatic type conversion.
 *  2. If a free function is better or equally good as a function template that already exists, the free function
 *     can be used.
 *  3. You can explicitly specify the type of the function template.
 *     func<type>(...)
 *  4. You can specify that you are only interested in a specific instantiation of a function template
 *     func<>(...)
 */
#include <iostream>
#include <string>
#include <vector>

// This function swaps the values passed as arguments.
template <typename T>
void xchg(T& x, T& y){
    T t = x;
    x = y;
    y = t;
}

// The only non-type, we use is N in the function templates below.
// This function returns the N times of the number passed n.
template <int N>
int nTimes(int n){
    return N * n;
}

int main(){
    std::cout << std::endl;

    bool t{true};
    bool f{false};

    std::cout << std::boolalpha;
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


    std::cout << "\n";

    std::cout << "nTimes<5>(10): " << nTimes<5>(10) << std::endl;
    std::cout << "nTimes<10>(5): " << nTimes<10>(5) << std::endl;

    std::cout << std::endl;

    return 0;
}