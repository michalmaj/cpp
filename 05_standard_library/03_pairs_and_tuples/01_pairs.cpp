/*
 * With std::pair, we can build pairs of arbitrary types. The class template std::pair needs the header
 * <utility>. std::pair has a default, copy and move constructor. Pair object can be swapped:
 *  std::swap(pair1, pair2);
 * Pairs will often be used in the C++ library. For example, the function std::minmax returns its result as
 * a pair, the associative container std::map, std::unordered_map, std::multimap, std::unordered_multimap
 * manage their key/vaue association in pairs.
 *
 * To get the element of a pair p, we can either access it directly or via an index. So, with p.frst or
 * std::get<0>(p) we get the first, with p.second or std::get<1>(p) we get the second element of the pair. 
 *
 * Pairs support the comparison operators ==, !=, <, >, <=, >=. If we compare two pairs for identity, at 
 * first the members pair1.first and pair2.first will be compared and then pair1.second and pair2.second.
 * The same strategy holds for the other comparison operators.
*/
#include <iostream>
#include <utility>

int main(){
    std::pair<const char*, double> charDoub("str", 3.14);
    std::pair<std::string, double> strDoub = std::make_pair("str", 3.14);
    auto charDoub1 = std::make_pair("str", 3.14);
    
    std::cout << charDoub.first << ", " << charDoub.second << "\n";    // str, 3.14
    charDoub.first = "Str";
    std::get<1>(charDoub) = 4.14;
    std::cout << charDoub.first << ", " << charDoub.second << "\n";    // Str, 4.14


    return 0;
}
