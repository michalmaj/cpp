/*
 * We can assign new elements to an existing container and, if required, swap two containers as well. If we
 * want to assign a container cont2 to another container cont1, we can do so either through copy assignemnt
 * cont1 = cont2 or move assignmet cint1 = std::move(cont2). In a move assignment, the value of cont2 is
 * copied to cont1 and cont2 becomes empty. A special form of assignment is the one with an initializer list
 * cont = {1, 2, 3, 4, 5}. In the case of std::array, an initializer list is not possible, hence we use
 * aggregate intialization. The function swap exists in two formas. It is a method cont1(swap(cont2)) and
 * also a function template: std::swap(cont1, cont2).
*/
#include <iostream>
#include <set>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::set<T>& s){
    for(const auto& e : s)
        out << e << " ";
    return out;
}


int main(){
    std::set<int> set1{0, 1, 2, 3, 4, 5};
    std::set<int> set2{6, 7, 8, 9};
    
    std::cout << "set1: " << set1 << std::endl;
    std::cout << "set2: " << set2 << std::endl;
    
    // Assign set2 to set1
    set1 = set2;

    std::cout << "set1: " << set1 << std::endl;
    std::cout << "set2: " << set2 << std::endl;
    
    // Move value of set2 in set1, in this case set2 becomes empty
    set1 = std::move(set2);

    std::cout << "set1: " << set1 << std::endl;
    std::cout << "set2: " << set2 << std::endl; // Print null since set2 is empty after the move operation
    
    // Give new values in set2
    set2 = {60, 70, 80, 90};
    
    std::cout << "set1: " << set1 << std::endl;
    std::cout << "set2: " << set2 << std::endl;
    
    // Swap both sets
    std::swap(set1, set2);
    std::cout << "set1: " << set1 << std::endl;
    std::cout << "set2: " << set2 << std::endl;

    return 0;
}
