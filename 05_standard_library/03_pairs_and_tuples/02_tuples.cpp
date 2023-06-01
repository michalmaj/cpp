/*
 * We can create tuples of arbitrary length and types with std::tuple. The class template needs the header
 * <tuple>. std::tuple is a generalization of std::pair. We can convert between tuples with two elements
 * and pairs. The tuple has, like std::pair, a default, a copy, and a move constructor. We can swap tuples
 * with the function std::swap.
 * 
 * The i-th element of a tuple t can be referenced by the function template std::get:
 *  std::get<i-1>(t).
 * By std::get<type>*t) we can directly refer to the element of the type type.
 * 
 * Tuples support the comparison operators ==, !=, <, >, <=, >=. If we compare two tuples, the elements of 
 * the tuples will be compared lexicograhically. The comparison starts at index 0.
 *
 * The helper function std::make_tuple is quite convenient for thr creation of tuples.
*/
#include <iostream>
#include <tuple>

int main(){
    std::tuple<std::string, int, float> t1("first", 3, 4.17f);
    auto t2 = std::make_tuple("second", 4, 1.1);

    std::cout << std::get<0>(t1) << ", " << std::get<1>(t1) << ", " << std::get<2>(t1) << "\n";
    std::cout << std::get<0>(t2) << ", " << std::get<1>(t2) << ", " << std::get<2>(t2) << "\n";
    
    std::cout << std::boolalpha << (t1 < t2) << std::endl;
    
    std::get<0>(t2) = "Second";
    
    std::cout << std::get<0>(t2) << ", " << std::get<1>(t2) << ", " << std::get<2>(t2) << "\n";
    std::cout << std::boolalpha << (t1 < t2) << std::endl;

    std::cout << std::get<float>(t1) << std::endl;
    
    auto pair = std::make_pair(1, true);
    std::tuple<int, bool> tup =  pair;

    return 0;
}
