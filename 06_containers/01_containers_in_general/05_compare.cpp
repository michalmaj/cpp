/*
 * Contaners support the comparison operators ==, !=, <, >, <=, >=. The comparison of two containers happens
 * on the elements of the contaners. When associative containers are compared, their keys are compared.
 * Unordered associative containers support only the comparison operator == and !=.
*/
#include <iostream>
#include <array>
#include <set>
#include <unordered_map>
#include <vector>

int main(){
    std::cout << std::boolalpha;
    
    std::vector<int> vec1{1, 2, 3, 4};
    std::vector<int> vec2{1, 2, 3, 4};
    std::cout << "vec1 == vec2: " << (vec1 == vec2) << std::endl; // true
    
    std::array<int, 4> arr1{1, 2, 3, 4};
    std::array<int, 4> arr2{1, 2, 3, 4};
    std::cout << "arr1 == arr2: " << (arr1 == arr2) << std::endl; // true
    
    std::set<int> set1{1, 2, 3, 4};
    std::set<int> set2{4, 3, 2, 1};
    std::cout << "set1 == set2: " << (set1 == set2) << std::endl; // true
    
    std::set<int> set3{1, 2, 3, 4, 5};
    std::cout << "set1 < set3: " << (set1 < set3) << std::endl; // true
    
    std::set<int> set4{1, 2, 3, -3};
    std::cout << "set1 > set4: " << (set1 > set4) << std::endl; // true
    
    std::unordered_map<int, std::string> um1{{1, "one"}, {2, "two"}};
    std::unordered_map<int, std::string> um2{{1, "one"}, {2, "Two"}};
    std::cout << "um1 == um2: " << (um1 == um2) << std::endl; // false
    

    return 0;
}
