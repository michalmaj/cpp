/*
 * We can copy ranges forward with std::copy, backward with std::copy_backward, and conditionally with
 * std::copy_if. If we want to copy n elements, we can use std::copy_n.
 *  std::copy - copies the range.
 *  std::copy_n - copies n elements.
 *  std::copy_if - copies the elements dependent on the predicate pre.
 *  std::copy_backwards - copies the range backward.
 *
 * The algorithms need input iterators and copy their elements to result. They return an end iterator to the
 * destination range.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 9};
    std::vector<int> myVec2(10);
    
    std::copy_if(myVec.begin(), myVec.end(), myVec2.begin() + 3, [](int a){return a % 2;});
    std::cout << "myVec2 contains: " << myVec2 << std::endl;
    std::cout << std::endl;
    
    std::string str{"Iamstring1"};
    std::string str2{"Hellostring---------------------2"};
    
    std::cout << "str2 contains: " << str2 << std::endl;
    std::copy_backward(str.begin(), str.end(), str2.end());
    std::cout << "str2 contains: " << str2 << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "str contains: " << str << std::endl;
    std::copy_backward(str.begin(), str.begin() + 5, str.end());
    std::cout << "str contains: " << str << std::endl;
    
    return 0;
}
