/*
 * There are special rules for the key and the value of an ordered associative container.
 * The key has to be:
 *  - sortable (by default, they are sorted in ascending order);
 *  - copyable and movable.
 * The value has to be:
 *  - default construcible;
 *  - copyable and movable.
 * The key associated with the value builds a pair p so that we get a member with p.first and the value with
 * p.second.
*/
#include <iostream>
#include <map>

int main(){
    std::multimap<char, int> mm = {
        {'a', 10},
        {'a', 20},
        {'b', 30}
    };
    
    for(const auto& [k, v] : mm)
        std::cout << "{" << k << "," << v << "}\n";

    return 0;
}
