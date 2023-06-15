/*
 * std::search searches for a range in another range from the beginning, std::find_end from the end.
 * std::search_n searches for n consecutive elements in the range.
 * All algorithms take a forard iterators, can be parametrized by a binary predicate, and return an end 
 * iterator for the first range, if the search was unseccessful.
*/
#include <iostream>
#include <array>
#include <cmath>
#include <algorithm>

int main(){
    std::cout << std::endl;
    
    std::array<int, 10> arr1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::array<int, 5> arr2{3, 4, -5, 6, 7};
    
    auto it = std::search(arr1.begin(), arr1.end(), arr2.begin(), arr2.end());
    
    if(it == arr1.end())
        std::cout << "arr2 is not in arr1\n";
    else{
        std::cout << "arr2 at position: " << std::distance(arr1.begin(), it) << " in arr1\n";
    }
    
    it = std::search(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), [](int a, int b){
        return std::abs(a) == std::abs(b);
    });

    if(it == arr1.end())
        std::cout << "arr2 is not in arr1\n";
    else{
        std::cout << "arr2 at position: " << std::distance(arr1.begin(), it) << " in arr1\n";
    }


    return 0;
}
