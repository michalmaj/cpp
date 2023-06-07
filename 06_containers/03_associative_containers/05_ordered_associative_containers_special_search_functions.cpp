/*
 * Ordered associative containers are optimized for searching, and so they offer unique search functions.
 *  Search function                     Description
 *  ordAssCont.count(key)               Returns the number of values with the key.
 *  ordAssCont.find(key)                Returns the iterator of key in ordAssCont. If there is no key in 
 *                                      ordAssCont it returns ordAssCont.end().
 *  ordAssCont.lower_bound(key)         Returns the iterator to the first key in ordAssCont in which key
 *                                      would be inserted.
 *  ordAssCont.upper_bound(key)         Returns the last position of key in ordAssCont in which key would
 *                                      be inserted.
 *  ordAssCont.equal_range(key)         Returns the range ordAssCont.lower_bound(key) and 
 *                                      ordAssCont.upper_bound(key) in a std::pair.
*/
#include <iostream>
#include <set>
#include <concepts>

template <typename T>
concept set_type = 
    std::same_as<T, std::multiset<typename T::key_type, typename T::key_compare, typename T::allocator_type>>;
    
template <set_type T>
std::ostream& operator<<(std::ostream& out, const T& t){
    for(const auto& e : t)
        out << e << " ";
    return out;
}
    
int main(){
    std::multiset<int> mySet{3, 1, 5, 3, 4, 5, 1, 4, 4, 3, 2, 2, 7, 6, 4, 3, 6};
    std::cout << "mySet contans: " << mySet << std::endl;
    
    // Erase in range
    mySet.erase(mySet.lower_bound(4), mySet.upper_bound(4)); // delete all instances of value 4
    std::cout << "mySet contans: " << mySet << std::endl;
    
    std::cout << "mySet.count(3): " << mySet.count(3) << std::endl; // 4 instances of value 3
    
    std::cout << "mySet.find(3): " << *mySet.find(3) << std::endl;
    std::cout << "mySet.lower_bound(3): " << *mySet.lower_bound(3) << std::endl;
    std::cout << "mySet.upper_bound(3): " << *mySet.upper_bound(3) << std::endl;
    
    auto pair = mySet.equal_range(3);
    std::cout << "(" << *pair.first << "," << *pair.second << ")\n";


    return 0;
}   
