/*
 * The four variations std::remove, std::remove_if, std::remove_copy, and std::remove_copy_if support two
 * kinds of operations. On one hand, remove elements with and without predicate from a range. On the oher
 * hand, remove elements with and without a predicate from a range. On the other hand, copy the result of 
 * our modification to a new range.
 *  std::remove -  removes the elements from the range, having the value val.
 *  std::remove_if - removes the elements from the range, fulfilling the predicate pred.
 *  std::remove_copy - removes the elements from the range, having the value val. Copies the result.
 *  std::remove_copy_if - removes the elements from the range, which fulfill the predicate pred. Copies the
 *                        result.
 *
 * The algorithms need input iterators for the source range and an output iterator for the destination 
 * range.
 * The return as a result an end iterator for the destination range.
 *
 * Apply the erase-remove idiom
 * The remove variations don't remove an element from the range. They return the new logical end of the 
 * range. We have to adjust the size of the container with the erase-remove idiom.
*/
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v){
    for(const auto& e : v)
        std::cout << e << " ";
    return out;
}

int main(){

    std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "myVec contains: " << myVec << std::endl;
    
    auto it = std::remove_if(myVec.begin(), myVec.end(), [](int a){return a % 2;});
    std::cout << "myVec contains: " << myVec << std::endl;
    
    
    myVec.erase(it, myVec.end());
    std::cout << "myVec contains: " << myVec << std::endl;
    
    std::cout << std::endl;
    
    std::string str{"Only for Testing Purpose."};
    std::cout << "str contains: " << str << std::endl;
    str.erase(std::remove_if(str.begin(), str.end(), [](char c){return std::isupper(c);}), str.end());
    std::cout << "str contains: " << str << std::endl;

    return 0;
}
