/*
 * std::move moves the ranges forward. std::move_backward moves the ranges backward.
 * Both algorithms need a destination iterator result, to which the range is moved. In the case of the 
 * std::move algorithm, this is an output iterator, and in the case of std::move_backward algorithm, this is
 * a bidirectional iterator. The algorithm return output or a bidirectional iterator, pointing to the 
 * initial position in the destination range.
 * Note: the source range may be changed. std::move and std::move_backward apply move semantics. Therefore
 * the source range is valid but does have not neccessarily the same elements afterward.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 9};
    std::vector<int> myVec2;
    
    std::move(myVec.begin(), myVec.end(), std::back_inserter(myVec2));
    std::cout << "myVec2 contains: " << myVec2 << std::endl;
    
    std::cout << "\n\n";
   
    std::string str{"abcdefghijklmnop"};
    std::string str2{"---------------------"};
    
    std::cout << str2 << std::endl;
    std::move_backward(str.begin(), str.end(), str2.end());
    std::cout << str2 << std::endl;

    return 0;
}
