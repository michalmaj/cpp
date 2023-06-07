/*
 * The insertion (insert and emplace) and deleton (erase) of elements in associative containers is similar 
 * to the rules of an std::vector. For an associative contaner that can have a key only once, the insertion
 * fails if the key is already in the contaner. Additionally, ordered associative containers support a
 * special function odrAssCont.erase(key), which removes all pairs with the key and returns their number.
*/
#include <iostream>
#include <set>
#include <array>
#include <concepts>

template <typename T>
concept set_type = 
    std::same_as<T, std::multiset<typename T::key_type, typename T::key_compare, 
                 typename T::allocator_type>>;
                 
                 
template <set_type Container>
std::ostream& operator<<(std::ostream& out, const Container& container){
    for(const auto& e : container)
        out << e << " ";
    return out;
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& out, std::array<T, N>& a){
    for(const auto& e : a)
        std::cout << e << " ";
    return out;
}

int main(){
    std::multiset<int> mySet{3, 1, 5, 3, 4, 5, 1, 4, 4, 3, 2, 2, 7, 6, 4, 3, 6};
    std::cout << "mySet contans: " << mySet << std::endl;
    
    // Add new element
    mySet.insert(8);
    
    // Add elements from another container
    std::array<int, 5> myArr{10, 11, 12, 13, 14};
    std::cout << "myArr contais: " << myArr << std::endl;
    mySet.insert(myArr.begin(), myArr.begin() + 3); // 10, 11, 12, without 13, because it's a range [s, s+n)
    std::cout << "mySet contans: " << mySet << std::endl;
    
    // Add elements initializer list
    mySet.insert({20, 21, 22});
    std::cout << "mySet contans: " << mySet << std::endl;

    // Erase value (4)
    std::cout << "mySet.erase(4): " << mySet.erase(4) << std::endl; // Erased 4 items
    std::cout << "mySet contans: " << mySet << std::endl; // no more 4 inside
    
    // Erase in range
    mySet.erase(mySet.lower_bound(5), mySet.upper_bound(15));
    std::cout << "mySet contans: " << mySet << std::endl; // no more values from 5 to 15 inside
    
    return 0;
}
