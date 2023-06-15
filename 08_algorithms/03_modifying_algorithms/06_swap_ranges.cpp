/*
 * std::swap and std::swap_ranges can swap objects and ranges.
 * The returned iterator points to the last swapped element in the destination range.
 * The ranges must not overlap
*/
#include <algorithm>
#include <iostream>
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
    std::vector<int> myVec2(myVec.size());
    
    std::cout << "myVec contains: " << myVec << ", address: " << &myVec << std::endl;
    std::cout << "myVec2 contains: " << myVec2 << ", address: " << &myVec2 << std::endl;

    std::cout << std::endl;
    
    std::swap(myVec, myVec2);
    
    std::cout << "myVec contains: " << myVec << ", address: " << &myVec << std::endl;
    std::cout << "myVec2 contains: " << myVec2 << ", address: " << &myVec2 << std::endl;
    
    std::cout << std::endl << std::endl;
    
    std::string str{"abcdefghijklmnop"};
    std::string str2{"---------------------"};

    std::cout << "str contains: " << str << ", address: " << &str << std::endl;
    std::cout << "str2 contains: " << str2 << ", address: " << &str2 << std::endl;

    std::cout << std::endl;
    
    std::swap_ranges(str.begin(), str.begin()+5, str2.begin()+5);
    
    std::cout << "str contains: " << str << ", address: " << &str << std::endl;
    std::cout << "str2 contains: " << str2 << ", address: " << &str2 << std::endl;
    
    
    return 0;
}
