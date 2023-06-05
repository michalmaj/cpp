/*
 * Try to access the index of the array that is greater than the size.
 * Use all three methods: [n], .at(), std::get<n>
*/
#include <iostream>
#include <array>

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, const std::array<T, N>& a){
    for(const auto& e : a)
        out << e << " ";
    return out;
}

int main() {
    // Write your code here     
    std::array<int, 5> arr{1, 2, 3, 4, 5}; // 5 elements, last index is 4
    std::cout << "arr contains: " << arr << std::endl;
  
    // Try to print out elelemnt at 5th index 
//    std::cout << "Accessing out of bound using []: " << arr[5] << std::endl; // Garbage data
//    std::cout << "Accessing out of bound using .at(n): " << arr.at(5) << std::endl; // std::out_of_range 
    // static assertion failed: array index is within bounds        
//    std::cout << "Accessing out of bound using std::get<n>: " << std::get<5>(arr) << std::endl;
  
  
  return 0;
}
