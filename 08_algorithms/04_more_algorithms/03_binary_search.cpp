/*
 * The fast search which has a search time of O(log n) has been predefined in C++.
 * The binary search algorithm use the fact that the ranges are already sorted. Th search for an element, 
 * use std::binary_search. With std::lower_bound we get an iterator for the first element, being no smaller
 * than the given value. With std::upper_bound we get an iterator back for the first element, which is 
 * bigger than the given value. std::equal_range combines both algorithms.
 *
 * If the container has n elements, we need on average log2(n) comparisons for the search. The binary search
 * requires that we use the same comparison criterion that we used for sorting the container. Per default
 * the comparison criterion is std::less, but we can adjust it. Our sorting criterion has to obey the strict
 * weak ordering. If not, the program is undefined.
 *
 * If we have an unordered associative container, the methods of the unordered associative container are in
 * general faster.
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

bool isLessAbs(int a, int b){
    return std::abs(a) < std::abs(b);
}

int main(){
    std::cout << std::boolalpha << std::endl;
    
    std::vector<int> vec{
        -3, 0, -3, 2, -3, 5, -3, 7, -0, 6, -3, 5, -6, 8, 9, 0, 8, 7, -7, 8, 9, -6, 3, -3, 2
    };
    std::cout << "vec contains: " << vec << std::endl;
    std::cout << std::endl;
    
    std::sort(vec.begin(), vec.end(), isLessAbs);
    std::cout << "vec after sorting: " << vec << std::endl;
    std::cout << std::endl;

    std::cout << "std::binary_search(vec.begin(), vec.end(), -5, isLessAbs): " <<
    std::binary_search(vec.begin(), vec.end(), -5, isLessAbs) << std::endl;
    
    std::cout << "std::binary_search(vec.begin(), vec.end(), 5, isLessAbs): " <<
    std::binary_search(vec.begin(), vec.end(), 5, isLessAbs) << std::endl;
    std::cout << std::endl;
    
    auto pair = std::equal_range(vec.begin(), vec.end(), 3, isLessAbs);
    std::cout << "Position of first 3: " << std::distance(vec.begin(), pair.first) << std::endl;
    std::cout << "Position of last 3: " << std::distance(vec.begin(), pair.second) - 1 << std::endl;
    
    for(auto threeIt = pair.first; threeIt != pair.second; ++threeIt)
        std::cout << *threeIt << " ";
    std::cout << std::endl;
    

    return 0;
}
