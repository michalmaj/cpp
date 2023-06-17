/*
 * This algorithm allows us to divide or split ranges into separate sets.
 * 
 * What is a partition?
 * A partition of a set os a decompositon of a set in subsets so that each element of the set is precisely
 * in one subset. The subsets are defined in C++ by unary predicate so that the members of the first subset
 * fulfill the predicate. The remaining elements are n the second subset.
 *
 * C++ offers a few functions for dealing with partitions. All of them need a unary predicate pre. 
 * std::partition and std::stable_partition partition a range and returns the partition point. With 
 * std::partition_point we can get the partition point of a partition. Afterwards we can check the partition
 * with std::is_partition or copy it with std::partition_copy.
 *
 * A std::stable_partition guarantees, in contrary to a std::partition, that the elements preserve their
 * relative order. The returned iterator FwdIt and BiIt points to the nitial position in the second subset
 * of the partition. The pair std::pair<OutIt, OutIt> of the algorithm std::partition_copy contains the end
 * iterator of the subsets result_true and result_false. The behavior of std::partition_point is undefined
 * if the range is not partitioned.
*/
#include <algorithm>
#include <cctype>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <concepts> // -std=c++20

template <typename T>
concept Seq = 
    std::same_as<T, std::vector<typename T::value_type, typename T::allocator_type>> ||
    std::same_as<T, std::list<typename T::value_type, typename T::allocator_type>> ||
    std::same_as<T, std::deque<typename T::value_type, typename T::allocator_type>>;
    
template <Seq Container>
std::ostream& operator<<(std::ostream& out, const Container& c){
    for(const auto& e : c)
        out << e << " ";
    return out;
} 

bool isOdd(int i) {return i % 2;}

int main(){
    std::cout << std::boolalpha;
    
    std::vector<int> vec{1, 4, 3, 4, 5, 6, 7, 3, 4, 5, 6, 0, 4, 8, 4, 6, 6, 5, 8, 8, 3, 9, 3, 7, 6, 4, 8};
    std::cout << "vec contains: " << vec << std::endl;

    std::cout << std::endl;
    
    auto parPoint = std::partition(vec.begin(), vec.end(), isOdd);
    std::cout << "vec contains: " << vec << std::endl;
    
    std::cout << "Fisrt set: ";
    for(auto i = vec.begin(); i != parPoint; ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    
    std::cout << "Second set: ";
    for(auto i = parPoint; i != vec.end(); ++i)
        std::cout << *i << " ";
    std::cout << std::endl;
    
    std::cout << "std::is_partitioned: " << std::is_partitioned(vec.begin(), vec.end(), isOdd) << "\n";
    std::cout << "std::partition_point: " << (std::partition_point(vec.begin(), vec.end(), isOdd) ==
                                              parPoint) << std::endl;
                                              
    std::cout << std::endl;
    
    std::list<int> li;
    std::list<int> de;
    
    std::partition_copy(vec.begin(), vec.end(), std::back_inserter(li), std::back_inserter(de),
    [](int i){return i < 5;});
    
    std::cout << "li contains: " << li << std::endl;
    std::cout << "de contains: " << de << std::endl;

    

    return 0;
}
