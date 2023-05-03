/*
 * A lambda function, or lambda, is a function without a name.
 * A lambda can be written in-place and doesn't require complete implementation outside the
 * scope of the main program.
 *
 * Syntax: []() -> {}
 * [] - Captures the used variables.
 * () - Necessary for parameters (optional).
 * -> - Necessary for complex lambda functions (optional).
 * {} - Functon body, per default const.
 *  []() mutable -> {} has a non-constant function body.
 *
 * The frst things we need to know is that lambdas are just functions objects automatically
 * created by the compiler.
 * A function object is an instance of a class for which the call operator, operator(), is
 * overloaded. This means that a function object is an object that behaves like a function.
 * The main difference between a function and a function object is that a function object is an
 * object and can, therefore, have a state.
 *
 * Lambda function can bind their invocation context. Binding allows any variables passed in the
 * surrounding scope (invocation context) to be passed to the lambda. Ths is what the [] in the
 * beginning is for. Within these square brackets, we can specify which variables we want the
 * lambda to capture. There are several types of bindings provided by C++ for lambda functions:
 *  []      - no binding;
 *  [a]     - a per copy;
 *  [&a]    - a per reference;
 *  [=]     - all used variables per copy;
 *  [&]     - all used variables per reference;
 *  [=,&a]  - per default per copy; a per reference;
 *  [&,a]   - per default per reference; a per copy;
 *  [this]  - data and member of the enclosing class per copy.
 *
 * With C++14, we have generic lambdas, which means that lambdas can deduce their arguments
 * types. Therefore, we can define a lambda expression such a [](auto a, auto b){return a+b;};.
 *
 * Note: We cannot overload lambdas, and a lambda can capture local variables.
*/

#include <iostream>
#include <vector> // STL dynamic array.
#include <numeric> // Numerics library includes common mathematical functions and types.

int main(){
    // Lambda function for adding two integers
    auto add_int = [](int a, int b){return a + b;};
    
    // Generic version of above lambda
    auto add_generic = [](auto a, auto b){return a + b;};
    
    // Vector of numbers
    std::vector<int> myVec{1, 2, 3, 4, 5};
    
    // https://en.cppreference.com/w/cpp/algorithm/accumulate
    auto res_int = std::accumulate(myVec.begin(), myVec.end(), 0, add_int);
    std::cout << "res_int: " << res_int << "\n";
    
    // Vecto of strings
    std::vector<std::string> myVecStr{"Hello ", "World"};
    auto st = std::accumulate(myVecStr.begin(), myVecStr.end(), std::string(), add_generic);
    std::cout << "st: " << st << "\n";

    return 0;
}
