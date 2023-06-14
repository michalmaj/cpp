/*
 * C++17 contains several algorithms to check whether a value or values in a range fulfill our given
 * condition.
 * The three functions std::all_of, std::any_of and std::none_of answer the question, if all, at least one
 * or no element of a range satisfies the condition. The functions need as argument input iterators and a
 * unary predicate and return a boolean.
 *  std::all_of - checks if all elements of the range satisfy the condition.
 *  std::any_of - checks if at least one element of the range satisfies the condition.
 *  std::none_of - checks if no element of the range satisfies the condiotion.
*/
#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    std::cout << std::boolalpha << std::endl;
    
    auto even = [](int i){return i % 2;};
    
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // At least one of elements inside myVec is even
    std::cout << "std::any_of: " << std::any_of(myVec.begin(), myVec.end(), even) << std::endl;
    
    // All elements inside myVec is even
    std::cout << "std::all_of: " << std::all_of(myVec.begin(), myVec.end(), even) << std::endl;
    
    // None of elements inside myVec is even
    std::cout << "std::none_of: " << std::none_of(myVec.begin(), myVec.end(), even) << std::endl;


    return 0;
}   
