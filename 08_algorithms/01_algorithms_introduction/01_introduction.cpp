/*
 * The Standard Template Library has a large number of algorithms to work with containers and their 
 * elements. As the algorithms are function templates, the are independent of the type of container 
 * elements. The glue between the containers and algorithms are the iterators. If your container supports 
 * the interface of an STL container, we can apply the algorithms to our container.
 * To use the algorithms, we have to keep a few rules in our heads.
 *
 * The algorithms are defined in various headers.
 * <algorithm> - contains the general algorithms.
 * <numeric> - contans the numeric algorithms.
 *
 * Many of the algorithms have the name suffix _if and _copy.
 * _if - the algorithm can be parametrized by a predicate.
 * _copy - the algorithm caopies its elements in another range.
 * Algorithms like: auto num = std::count(InpIt first, InpIt last, const T& val) return the number of 
 * elements that are equal to val. num is of type iterator_traits<InpIt>::difference_type. We have the 
 * guarantee that numis sufficient to hold the resut. Because of the automatic return type deduction with
 * auto, the compiler will give us the right types.
 *
 * If the container uses an additional range, it has to be valid
 * The algorithm std::copy_if uses an iterator to the beginning of its destination range. This destination
 * range has to be valid.
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <concepts> // -std=c++20

template <typename T>
concept seq =
    std::same_as<T, std::vector<typename T::value_type, typename T::allocator_type>> ||
    std::same_as<T, std::deque<typename T::value_type, typename T::allocator_type>> ||
    std::same_as<T, std::list<typename T::value_type, typename T::allocator_type>>;
    
template <seq T>
std::ostream& operator<<(std::ostream& out, const T& t){
    for(const auto& e : t)
        out << e << " ";
    return out;
}

template <typename Cont, typename T>
void doTheSame(Cont cont, T t){
    std::cout << "cont.size(): " << cont.size() << std::endl;   
    std::cout << "cont contains: " << cont << std::endl;
  
    std::reverse(cont.begin(), cont.end());
    std::cout << "reversed cont: " << cont << std::endl;
    
    std::reverse(cont.begin(), cont.end());
    std::cout << "again reversed cont: " << cont << std::endl;
    
    // Find value
    auto it = std::find(cont.begin(), cont.end(), t);
    
    // Reverse from given iterator to the end
    if(it == cont.end())
        return;
    
    std::reverse(it, cont.end());
    std::cout << "reversed cont by " << t << " value: " << cont << std::endl;
}


int main(){
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::deque<std::string> myDeq({"A", "B", "C", "D", "E", "F", "G", "H", "I"});
    std::list<char> myList({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'});
    
    std::cout << "vector in function:\n";
    doTheSame(myVec, 5);
    std::cout << "\n\n";

    std::cout << "dequeue in function:\n";
    doTheSame(myDeq, "D");
    std::cout << "\n\n";
    
    std::cout << "list in function:\n";
    doTheSame(myList, 'd');
    std::cout << "\n\n";

    return 0;
}
