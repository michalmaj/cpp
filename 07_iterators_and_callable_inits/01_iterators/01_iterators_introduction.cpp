/*
 * On the one hand, iterators are generalizations of pointers which represents positions in a container. On
 * the other hand, they provide powerful iteration and random access in a container.
 * Iterators are glue between the generic containers and the generic algorithms of the Standard Template
 * Library.
 * Iterators support the following operations
 *  *: Returns the element at the current position.
 *  ==, !=: Compares two positions.
 *  =: Assigns a new value to an iterator.
 *
 * Note:
 * The range-based for-loop usues the iterators implicitly.
 * Because iterators are not checked, they have the same issues as pointers.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <iterator> // For correct version

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::deque<T>& d){
    for(const auto& e : d)
        out << e << " ";
    return out;
}

int main(){
    std::vector<int> vec{1, 23, 3, 3, 3, 4, 5};
    std::deque<int> deq;
    
    // Start iterator bigger than end iterator
    std::copy(vec.begin()+2, vec.begin(), deq.begin());
    
    std::cout << "deq contains: " << deq << std::endl;
    
    // Taget contaner is too small
    std::copy(vec.begin(), vec.end(), deq.end());
    
    std::cout << "deq contains: " << deq << std::endl;

    // Correct version with std::back_inserter: https://en.cppreference.com/w/cpp/iterator/back_inserter
    std::copy(vec.begin(), vec.end(), std::back_inserter(deq));
    
    std::cout << "deq contains: " << deq << std::endl;
    return 0;
}
