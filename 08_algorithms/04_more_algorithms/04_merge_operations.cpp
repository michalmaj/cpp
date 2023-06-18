/*
 * Merge operations empower us to merge sorted rnges in a new sorted range. The algorithm requires that the
 * ranges and the algorithm use the same sorting criterion. If not, the program is undefined. Per default
 * the predefined sorting criterion std::less is used. If we use our sorting criterion, it has to obey the
 * strict weak ordering. If not, the program is undefined.
 * We can merge two sorted ranges with std::_inplace_merge and std::merge. We can check with std::includes 
 * if one sorted range is in another sorted range. Wecan merge with std::set_difference, 
 * std::set_intersection, std::set_symmetric_difference and std::set_union two sorted ranges in a new sorted
 * range.
 * The returned iterator is an end iterator for the destnation range. The destination range of 
 * std::set_difference has all elements in the first, but not the second range.. On the contrary, the
 * destinaton range of std::symmetric_difference has only the elements that are elements of one range, but
 * not both. std::unon determines the union of both sorted ranges.
*/
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>
#include <concepts> // -std=c++20

template <typename T>
concept Seq = 
    std::same_as<T, std::vector<typename T::value_type, typename T::allocator_type>> ||
    std::same_as<T, std::deque<typename T::value_type, typename T::allocator_type>>;
    
template <Seq Container>
std::ostream& operator<<(std::ostream& out, const Container& c){
    for(const auto& e : c)
        out << e << " ";
    return out; 
}

int main(){
    std::cout << std::boolalpha;
    
    std::vector<int> vec1{1, 1, 4, 3, 5, 8, 6, 7, 9, 2};
    std::vector<int> vec2{1, 2, 3};

    std::cout << "vec1 contains: " << vec1 << std::endl;
    std::cout << "vec2 contains: " << vec2 << std::endl;
    std::cout << std::endl;
    
    std::sort(vec1.begin(), vec1.end());
    std::vector<int> vec(vec1);
    std::cout << "vec1 includes vec2: " << std::includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end())
    << std::endl;
    std::cout << std::endl;
    
    vec1.reserve(vec1.size() + vec2.size());
    std::cout << "vec1 contains: " << vec1 << std::endl; 
    
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    std::cout << "vec1 after inserton: " << vec1 << std::endl; 
    std::cout << std::endl;
    
    std::inplace_merge(vec.begin(), vec1.end() - vec2.size(), vec1.end());
    std::cout << "vec1 after merge: " << vec1 << std::endl; 
    std::cout << std::endl;
    
    vec2.push_back(10);
    std::cout << "vec1 contains: " << vec1 << std::endl;
    std::cout << "vec2 contains: " << vec2 << std::endl;
    std::cout << std::endl;
    
    std::vector<int> res;
    std::set_union(vec.begin(), vec.end(), vec2.begin(), vec2.end(), std::back_inserter(res));
    std::cout << "union between: " << vec << "and " << vec2 << std::endl;
    std::cout << "is: " << res << std::endl;
    std::cout << std::endl;
    
    res = {};
    std::set_intersection(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
        std::back_inserter(res));
    std::cout << "intersection between: " << vec << "and " << vec2 << std::endl;
    std::cout << "is: " << res << std::endl;
    std::cout << std::endl;
    
    res = {};
    std::set_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(), std::back_inserter(res));
    std::cout << "set difference between: " << vec << "and " << vec2 << std::endl;
    std::cout << "is: " << res << std::endl;
    std::cout << std::endl;
    
    res = {};
    std::set_symmetric_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
        std::back_inserter(res));
    std::cout << "set symetric difference between: " << vec << "and " << vec2 << std::endl;
    std::cout << "is: " << res << std::endl;

    return 0;
}
