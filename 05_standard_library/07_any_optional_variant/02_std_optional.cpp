/*
 * std::optional is very convenient when the value of our object can be null or empty.
 * std::optional is quite comfortable for calculations such as database queries that may have a result.
 *
 * Don't use no-results
 * Before C++17 it was common practice to use a special value such a null pointer, an empty string, or a
 * unique integer to denote the absence of a result. These special values or no-result are very error-prone
 * because we have to misuse the type system to check the return value. This means that for the type system
 * thet we have to use a regular value such as an empty string to define an irregular value.
 *
 * The various constructors and the convenience function std::make_optional let us define an optional object
 * opt with or without a value. opt.emplace will construct the contained value in-place and opt.reset will
 * destroy the container value. We can explicitly ask a std::optional container if it has a value or we can
 * check it in a logical expression. opt.value returns the value and opt.value_or returns the value or a
 * default value. If opt has no contained value, the call opt.value will throw a std::bad_optional_access
 * exception.
*/
#include <iostream>
#include <optional>
#include <vector>

std::optional<int> getFirst(const std::vector<int>& vec){
    if(!vec.empty())
        return std::optional<int>(vec.at(0));
    return std::optional<int>();
}

int main(){
    std::vector<int> myVec{1, 2, 3};
    std::vector<int> myEmptyVec;
    
    auto myInt = getFirst(myVec);
    
    if(myInt){
        std::cout << *myInt << std::endl;
        std::cout << myInt.value() << std::endl;
        std::cout << myInt.value_or(2023) << std::endl;
    }
    
    auto myEmptyInt = getFirst(myEmptyVec);
    
    if(myEmptyInt){
        std::cout << *myEmptyInt << std::endl;
        std::cout << myEmptyInt.value() << std::endl;
        std::cout << myEmptyInt.value_or(2023) << std::endl;
    }
    if(!myEmptyInt)
        std::cout << myEmptyInt.value_or(2023) << std::endl;



    return 0;
}
