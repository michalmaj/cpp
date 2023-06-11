/*
 * Function objects
 * At first, don't call them functors. That's a well-defined term from the category threory.
 * Function objects are objects behaves like functions. They achieve this due to their call operator being
 * implemented. As functions objects are objects, they can have attributes and therefore state.
 *
 * Predefined Function Objects
 * C++ offers a bunch of predefined function objects. They need the header <functional>. These predefined
 * function objects are very useful to change the default behaviour of the containers. For example, the 
 * keys of the ordered associative containers are by default sorted with the predefined function object
 * std::less. But we may want to use std::greater instead.
 * There are function objects in the Standard Template Library for arithmetic, logic, and bitwise operations
 * and also for negation and comparison: https://en.cppreference.com/w/cpp/utility/functional
 * Negation: std::negate<T>()
 * Arithmetic: std::plus<T>(), std::minus<T>(), std::multiplies<T>(), std::divides<T>(), std::modulus<T>()
 * Comparison: std::equal_to<T>(), std::not_equal_to<T>(), std::less<T>(), std::greater<T>(), 
               std::less_equal<T>(), std::greater_equal<T>()
 * Logical: std::logcal_not<T>(), std::logical_and<T>(), std::logical_or<T>()
 * Bitwise: std::bit_and<T>(), std::bit_or<T>(), std::bit_xor<T>()
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <ranges> // -std=c++20

struct Square{
    void operator()(int& i){i *= i;}
};

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "myVec contains: " << myVec << std::endl;
    
    std::ranges::for_each(myVec, Square());
    std::cout << "myVec contains: " << myVec << std::endl;

    return 0;
}
