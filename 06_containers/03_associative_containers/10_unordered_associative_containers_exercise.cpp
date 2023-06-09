/*
 * Use std::unordered_set instead of std::unordered_map and std::unordered_multiset instead of
 * std::unordered_multimap in the program.
 * std::set, std::multiset, and all variatons are only degenerated version os std::map and std::multimap,
 * missing the associated value.
*/ 
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <set>
#include <unordered_set>
#include <concepts> // -std=c++20

template <typename T>
concept map_type =
    std::same_as<T, std::map<typename T::key_type, typename T::mapped_type, typename T::key_compare,
                             typename T::allocator_type>> ||
    std::same_as<T, std::multimap<typename T::key_type, typename T::mapped_type, typename T::key_compare,
                                  typename T::allocator_type>> ||
    std::same_as<T, std::unordered_map<typename T::key_type, typename T::mapped_type, typename T::hasher, 
                                       typename T::key_equal, typename T::allocator_type>> ||
    std::same_as<T, std::unordered_multimap<typename T::key_type, typename T::mapped_type, 
                                            typename T::hasher, typename T::key_equal, 
                                            typename T::allocator_type>>;
                                            
template <typename T>
concept set_type = 
    std::same_as<T, std::set<typename T::key_type, typename T::key_compare, typename T::allocator_type>> ||
    std::same_as<T, std::multiset<typename T::key_type, typename T::key_compare, 
                                  typename T::allocator_type>> ||
    std::same_as<T, std::unordered_set<typename T::key_type, typename T::hasher, typename T::key_equal,
                                       typename T::allocator_type>> ||
    std::same_as<T, std::unordered_multiset<typename T::key_type, typename T::hasher, typename T::key_equal,
                                            typename T::allocator_type>>;

template <map_type M>
std::ostream& operator<<(std::ostream& out, const M& m){
    for(const auto& [k, v] : m)
        out << "{" << k << ", " << v << "} ";
    return out;
}

template <set_type S>
std::ostream& operator<<(std::ostream& out, const S& s){
    for(const auto& k : s)
        out << k << " ";
    return out;
}


int main(){

    // std::unordered_map and std::unordered_multimap 
    std::cout << std::endl;
    constexpr long long home = 497'074'123'456;
    constexpr long long mobile = 4'916'046'123'356;
    
    // constructor
    std::unordered_multimap<std::string, long long> multiMap{
        {"grimm", home}, {"grimm", mobile}, {"jaud-grimm", home}
    };
    
    std::unordered_map<std::string, int> uniqMap{
        {"bin", 1}, {"root", 0}, {"nobody", 65834}, {"rainer", 1000}
    };

    std::cout << "multiMap contains: " << multiMap << std::endl;
    std::cout << "uniqMap contains: " << uniqMap << std::endl;
    
    // Insert new elements
    constexpr long long work = 4'970'719'754'513;
  
    multiMap.insert({"grimm", work});  
    // Won't work
//    multiMap["grimm-jaud"] = 4'916'012'323'356;
    
    uniqMap["lp"] = 4;
    uniqMap.insert({"sshd", 71});
    
    std::map<std::string, int> myMap{{"ftp", 40}, {"rainer", 999}};
    uniqMap.insert(myMap.begin(), myMap.end());
    multiMap.insert(myMap.begin(), myMap.end());
    
    std::cout << std::endl;

    std::cout << "multiMap contains: " << multiMap << std::endl;
    std::cout << "uniqMap contains: " << uniqMap << std::endl;
    
    std::cout << std::endl;
    
    // Search for elements
    
    
    // Search for grimm in multiMap
    auto iter1 = multiMap.equal_range("grimm");
    std::cout << "grimm: ";
    for(auto it = iter1.first; it != iter1.second; ++it)
        std::cout << it->second << " ";
    std::cout << std::endl;
    std::cout << R"(multiMap.count("grimm"): )" << multiMap.count("grimm") << std::endl;
    
    // Search for root in uniqMap
    auto iter2 = uniqMap.find("root");
    if(iter2 != uniqMap.end()){
        std::cout << R"(uniqMap.find("root"): )" << iter2->second << std::endl;
        std::cout << R"(uniqMap["root"]: )" << uniqMap["root"] << std::endl;
    }
    
    std::cout << std::endl;
    
    // Will create a new entyr
    std::cout << R"(uniqMap["notAvailable"]: )" << uniqMap["notAvailable"] << std::endl;
    std::cout << "uniqMap contains: " << uniqMap << std::endl;
    
    std::cout << std::endl;
    
    // Remove elements
    int numMulti = multiMap.erase("grimm"); // Return how many elements are erased
    int numUniq = uniqMap.erase("rainer"); // Return either 1 or 0
    
    std::cout << "Erased " << numMulti << " rimes grimm from multiMap\n";
    std::cout << "Erased " << numUniq << " rimes reiner from uniqMap\n";
    
    std::cout << std::endl;
    
    // Clear all elements
    multiMap.clear();
    uniqMap.clear();
    
    std::cout << "multiMap.size(): " << multiMap.size() << std::endl;
    std::cout << "uniqMap.size(): " << uniqMap.size() << std::endl;
    
    
    // std::unordered_set and std::unordered_multiset
    std::cout << std::endl;
    
    // constructor
    std::unordered_multiset<int> multiSet{1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::unordered_set<int> uniqSet(multiSet.begin(), multiSet.end());
    
    std::cout << "multiSet contains: " << multiSet << std::endl;
    std::cout << "uniqSet contains: " << uniqSet << std::endl;
    
    // Insert new elements
    multiSet.insert(-1000);
    uniqSet.insert(-1000);
    
    // Insert multiple elements
    std::set<int> mySet{-5, -4, -3, -2, -1};
    multiSet.insert(mySet.begin(), mySet.end());
    uniqSet.insert(mySet.begin(), mySet.end());
    
    std::cout << "multiSet contains: " << multiSet << std::endl;
    std::cout << "uniqSet contains: " << uniqSet << std::endl;
    
    // Search for elements
    // search for elements
    auto it = uniqSet.find(5);
    if (it != uniqSet.end()){
        std::cout << "uniqSet.find(5): " << *it << std::endl;
    }

    std::cout << "multiSet.count(5): " << multiSet.count(5) << std::endl;

    std::cout << std::endl;

    // remove
    numMulti = multiSet.erase(5);
    numUniq = uniqSet.erase(5);

    std::cout << "Erased " << numMulti << " times 5 from multiSet." << std::endl;
    std::cout << "Erased " << numUniq << " times 5 from uniqSet." << std::endl;

    // all
    multiSet.clear();
    uniqSet.clear();

    std::cout << std::endl;

    std::cout << "multiSet.size(): " << multiSet.size() << std::endl;
    std::cout << "uniqSet.size(): " << uniqSet.size() << std::endl;
    
    return 0;
}
