/*
 * The default comparison criterion of the ordered associative containers is std::less. If we want to use a
 * user-defined type as the key, we have to overload the operator<. It's sufficient to overload the 
 * operator< for our data because the C++ runtime compares, with the help of the relation:
 *  (! (elem1 < elem2 || elem2 < elem1))
 *
 * We can specify the sorting criterion as a template argument that must implement a strict weak ordering.
 * Strict weak ordering for a sorting criterion on a set S is given if the following requirements are met:
 *  - For every s fromS it has to hold that s < s is not possible.
 *  - For all s1 and s2 from S it must hold: If s1 < s2, then s2 < s1 is not possible.
 *  - For all s1, s2, s3 with s1 < s2 and s2 < s3 the following must hold: s1 < s3.
 *  - For all s1, s2, s3 with s1 not comparable with s2 and s2 not comparable with s3 the following must
 *    hold: s1 is not comparable with s3.
 * In contrast to the definition of the stric weak ordering, the usage of a comparison criterion with strict
 * weak ordering is a lot simpler for an std::map.
*/
#include <iostream>
#include <map>

int main(){
    std::map<int, std::string, std::greater<>> int2str{
        {5, "five"}, {1, "one"}, {4, "four"}, {3, "three"},
        {2, "two"}, {7, "seven"}, {6, "six"}, {8, "eight"}
    };
    
    for(const auto& [k, v] : int2str)
        std::cout << "{" << k << "," << v << "} ";
    std::cout << std::endl;

    return 0;
}
