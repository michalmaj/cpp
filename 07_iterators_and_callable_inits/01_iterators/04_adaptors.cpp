/*
 * Iterator adaptors enable the use of iterators in insert mode or with streams. They need the header 
 * <iterator>
 *
 * Insert iterators
 * With the three insert iterators std::front_inserter, std::back_inserter and std::inserter we can insert
 * an element into a container at the beginning, at the end, or an arbitrary position respectively. The 
 * memory for the elements weill automatically be provided. The three map their functionality on the 
 * underlyng methods of the container cont.
 * The table below gives us two pieces of information: Which methods of the containers are internally used
 * and which iterators can be used depends on the container's type.
 *  -----------------------------------------------------------------------------------------
 *  |Name                           |Internally-used Method             |Container          |
 *  |-------------------------------|-----------------------------------|------------------ |
 *  |std::fron inserter(val)        |const.push_front(val)              |std::deq           |
 *  |                               |                                   |std::list          |
 *  |-------------------------------|-----------------------------------|-------------------|
 *  |std::back_inserter(val)        |const.push_back(val)               |std::vector        |
 *  |                               |                                   |std::deq           |
 *  |                               |                                   |std::list          |
 *  |                               |                                   |std::string        |
 *  |-------------------------------|-----------------------------------|-------------------|
 *  |std::inserter(val, pos)        |cont.insert(pos, val)              |std::map           |
 *  |                               |                                   |std::set           |
 *  |                               |                                   |std::vector        |
 *  |                               |                                   |std::deq           |
 *  |                               |                                   |std::list          |
 *  |                               |                                   |std::string        |
 *  -----------------------------------------------------------------------------------------
*/
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <concepts> // -std=c++20
#include <ranges> // -std=c++20

template <typename T>
concept seq = 
    std::same_as<T, std::deque<typename T::value_type, typename T::allocator_type>> ||
    std::same_as<T, std::vector<typename T::value_type, typename T::allocator_type>>;

template <seq T>
std::ostream& operator<<(std::ostream& out, const T& t){
    for(const auto& e : t)
        out << e << " ";
    return out;
}

int main(){
    std::deque<int> deq{5, 6, 7, 10, 11, 12};
    std::cout << "deq contains: " << deq << std::endl;
    
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    
    // Copy elements from vec (find 13 nd put from 13 to the end into deq)
    std::copy(std::find(vec.begin(), vec.end(), 13), vec.end(), std::back_inserter(deq));
    
    std::cout << "deq contains: " << deq << std::endl;
    
    // Copy elements from 8 to 10 (exclusively)
//    std::copy(std::find(vec.begin(), vec.end(), 8), std::find(vec.begin(), vec.end(), 10),
//              std::inserter(deq, std::find(deq.begin(), deq.end(), 10)));
    
    // Above version with ranges
    std::copy(std::ranges::find(vec, 8), std::ranges::find(vec, 10), 
              std::inserter(deq, std::ranges::find(deq, 10)));
    std::cout << "deq contains: " << deq << std::endl;
    
    // Copy elements from 1 to 5 from vec to deq using reverse iterator
    std::copy(vec.rbegin()+11, vec.rend(), std::front_inserter(deq));
    std::cout << "deq contains: " << deq << std::endl;

    return 0;
}
