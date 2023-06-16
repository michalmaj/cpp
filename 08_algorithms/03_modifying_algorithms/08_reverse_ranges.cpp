/*
 * std::reverse and std::reverse_copy invert the order of the elements in their range.
 * Both algorithms require bidirectonal iterators. The returned iterator points to the position of the 
 * output range result before the elements were copied.
*/
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
    std::same_as<T, std::list<typename T::value_type, typename T::allocator_type>> ||
    std::same_as<T, std::deque<typename T::value_type, typename T::allocator_type>>;
    
template <seq Container>
std::ostream& operator<<(std::ostream& out, const Container& c){
    for(const auto& e : c)
        out << e << " ";
    return out;
}

template <typename Cont, typename T>
void doTheSame(Cont cont, T t){
    std::cout << "cont contains: " << cont << std::endl;
    std::cout << "cont.size(): " << cont.size() << std::endl;
    std::cout << std::endl;
    
    std::reverse(cont.begin(), cont.end());
    std::cout << "cont reversed: " << cont << std::endl;
    std::cout << std::endl;
    
    std::reverse(cont.begin(), cont.end());
    std::cout << "cont reversed again: " << cont << std::endl;
    std::cout << std::endl;
    
    auto it = std::find(cont.begin(), cont.end(), t);
    if(it == cont.end())
        return;
    std::reverse(it, cont.end());
    std::cout << "cont reversed by " << t << ": " << cont << std::endl;
}

int main(){
    std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    std::deque<std::string> myDeque({"A", "B", "C", "D", "E", "F", "G", "H", "I"});
    std::list<char> myList({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'});
    
    doTheSame(myVec, 5);
    std::cout << "---------------------------------------------------------------------" << std::endl;

    doTheSame(myDeque, "D");
    std::cout << "---------------------------------------------------------------------" << std::endl;
    
    doTheSame(myList, 'd');
    std::cout << "---------------------------------------------------------------------" << std::endl;

    return 0;
}
