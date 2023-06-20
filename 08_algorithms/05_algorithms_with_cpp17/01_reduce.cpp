/*
 * The six new algorithms that are typically used for parallel execution known under the name prefix sum. If
 * the given binary callables are not associative and commutative, the bahavior of the algorithm is 
 * undefined.
 *
 * reduce:
 * This reduce the elements of the range. init is the start value. Behaves the same as std::accumulate but
 * the range may be rearranged.
 *
 * transform_reduce:
 * This transforms and reduces the elements of one or two ranges. init is the start value.
 *  Behaves similarly to std::inner_product but the range may be rearranged.
 *  If applied to two ranges:
 *      - if not provided, multiplication is used for transforming the ranges into one range, and addition
 *        is used to reduce the intermediate-range into the result
 *      - if provided, un1 is used for the transforming step and fun2 is used for the reducing step
 *  If applied to a single range
 *      - fun2 is used for transforming the given range.
 *
 * MapReduce in C++17
 * The Haskell function map is called std::transform in C++. When we substitute transform with map in the
 * name std::transform_reduce, we will get std::map_reduce. MapReduce is the well-known parallel framework
 * that first maps each value to a new value, then reduces in the second phase all values to the result.
 * The algorithm is directly applicable in C++17. In the following example, in the map phase, each word is
 * mapped to its length, and the length of all worlds are then reduced to their sum during the reduce phase.
 * The result is the sum of the length of all words.
*/
#include <iostream>
#include <vector>
#include <numeric>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v){
    for(const auto& e : v)
        out << e << " ";
    return out;
}

int main(){

    std::vector<int> vec{4, 2, 9, 7, 12, 19, 1};
    auto sum = std::reduce(vec.begin(), vec.end(), 0);
    std::cout << "sum: " << sum << std::endl;
    
    std::cout << std::endl;
    
    std::vector<std::string> str{"Only", "for", "testing", "purpose"};
    
    size_t result = std::transform_reduce(
                        str.begin(), str.end(), 0,
                        [](size_t a, size_t b){return a + b;},
                        [](const std::string& s){return s.length();}
    );
    std::cout << "result: " << result << std::endl;
    return 0;
}
