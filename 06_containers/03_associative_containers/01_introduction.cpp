/*
 * C++ has eght different associative containers. Four of them are associative containers with sorted keys:
 * std::set, std::map, std::multiset, std::multimap. The other four are associative containers with unsorted
 * keys: std::unsorted_set, std::unsorted_map, std::unsorted_multiset, std::unordered_multimap. The 
 * associative containers are special containers.
 *
 * All eight ordered and unordered containers have one thing in common: they associate a key with a value. 
 * We can use the key to get value. To classify the associative containers, there simple questions need to
 * be answered:
 *  1. Are the keys sorted?
 *  2. Does the key have an associated value?
 *  3. Can a key appear more than once?
 * The following table with 2^3 = 8 rows gives the answers to the threee questions. The answer to a fourth
 * question is in the table. How fast is the access time of a key in the best case?
 *  Contaner                    Sorted      Associated value        More identical keys     Access time
 *  std::set                    yes         no                      no                      logarithmic
 *  std::unordered_set          no          no                      no                      constant
 *  std::map                    yes         yes                     no                      logarithmic
 *  std::unordered_map          no          yes                     no                      constant
 *  std::multiset               yes         no                      yes                     logarithmic
 *  std::unordered_multiset     no          no                      yes                     constant
 *  std::multimap               yes         yes                     yes                     logarithmic
 *  std::unordered_multimap     no          yes                     yes                     constant
 *
 * Since C++98, there have been ordered associative containers; with C++11 came unordered associative
 * containers. Both classes have a vary similar interface. That's the reason that the example below is
 * identical for std::map and std::unordered_map. To be more precise, the interface os std::unordered_map is
 * a superset of the interface std::map. The same holds true for the remaining three unordered associative
 * contaners. So, porting our code from the ordered to unordered containers is quite easy.
 * 
 * We can initialize the contaners with an initializer list and add new elements with the index operator. To
 * access the first element of the key-value pair p, we have p.first, and for the second element, we have
 * p.second. p.first is the key and p.second is the aoociative value of the pair.
*/
#include <iostream>
#include <map>
#include <unordered_map>


// In overloading operator<< we can use a structured binding (C++17)
// We have to use 3 or even 4 typenames: for key, value, comparator and allocator.
template <typename K, typename V, typename Compare>
std::ostream& operator<<(std::ostream& out, const std::map<K, V, Compare>& m){
    size_t len = m.size();
    for(const auto& [k, v] : m){
        len--;
        if(len)
            out << "{" << k << "," << v << "}\n";
        else
            out << "{" << k << "," << v << "}";
    }
    return out;
}

template <typename K, typename V, typename Hash, typename Equal, typename Alloc>
std::ostream& operator<<(std::ostream& out, const std::unordered_map<K, V, Hash, Equal, Alloc>& um){
    size_t len = um.size();
    for(const auto& [k, v] : um){
        len--;
        if(len)
            out << "{" << k << "," << v << "}\n";
        else
            out << "{" << k << "," << v << "}";
    }
    return out;  
}

int main(){
    // By deafult keys are sorted in ascending way (for descending: std::greater<>)
    std::map<std::string, int> m{ 
        {"John", 1972},
        {"Arya", 1986}
    };
    m["Ned"] = 1954;
    std::cout << m["Ned"] << std::endl; // 1954
    std::cout << std::endl;
    
    // Will be printed in sorted way (ascending)
    for(const auto& p : m) std::cout << "{" << p.first << "," << p.second << "}\n";
    std::cout << std::endl;
    
    // Using overloading operator<<
    std::cout << m << std::endl;
    std::cout << std::endl;
    
    m.erase("Arya");
    std::cout << m << std::endl;
    std::cout << std::endl;
    
    m.clear();
    std::cout << "m.size(): " << m.size() << std::endl << std::endl;
    
    std::unordered_map<std::string, int> um{ 
        {"John", 1972},
        {"Arya", 1986}
    };
    um["Ned"] = 1954;
    std::cout << um["Ned"] << std::endl; // 1954
    std::cout << std::endl;
    
    std::cout << um << std::endl << std::endl;
    
    um.erase("Arya");
    std::cout << um << std::endl << std::endl;
    
    um.clear();
    std::cout << "um.size(): " << um.size() << std::endl;
    
    
    return 0;
}

