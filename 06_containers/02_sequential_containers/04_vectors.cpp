/*
 * std::vector vec has a few methods to access its elements. vec.front(), yields the first element, and
 * vec.back() yields the last element of vec. To read or write the (n+1)-th elelemnt of vec, we can use the
 * index operator vec[n] or method vec.at(n). The second one checks the boundaries of vec, so that we 
 * eventually get an std::range_error exception. Besides the index operator, std::vector offers additional 
 * methods to assign, insert, create or remove elements:
 *  Method                          Description
 *  vec.assign(...)                 Assign one or more elements, a range or an initializer list.
 *  vec.clear()                     Removes all elements from vec.
 *  vec.emplace(pos, args, ...)     Creates a new element before pos with the args in vec and returns the
 *                                  the new position of the element.
 *  vec.emplace_back(args, ...)     Creates a new element in vec with args... .
 *  vec.erase(...)                  Removes one element or a range and returns the next position.
 *  vec.insert(pos, ...)            Inserts one or more elements, a range or an initializer list and returns
 *                                  the new position of the element.
 *  vec.push_back(elem)             Adds a copy of elem at the ond of vec.
 *
 * Size vs. Capacity
 * The number of elements an std::vector has usually take up less space than what is already reserved. There
 * is a simple reason for this. With extra memory already allocated, the size of the std::vector can 
 * increase without an expensive allocation of new memory.
 *  Method                  Description
 *  vec.size()              Return the number of elements of vec.
 *  vec.capacity()          Return the number of elements, which vec can have without reallocation.
 *  vec.resize(n)           vec will be increased to n elements.
 *  vec.reserve(n)          Reserve memoty for at least n elements.
 *  vec.shrink_to_fit()     Reduces capacity of vec to the size.
 * Note: The call vac.shrik_to_fit() is not binding. That means the runtime can ignore t. But on popular 
 * platforms, it always observed the desired behavior.
*/
#include <iostream>
#include <vector>


int main(){
    std::vector<int> intVec1(5, 2023);
    intVec1.reserve(10);
    std::cout << "intVec1.size(): " << intVec1.size() << std::endl; // 5
    std::cout << "intVec1.capacity(): " << intVec1.capacity() << std::endl; // 10
    
    intVec1.shrink_to_fit();
    std::cout << "intVec1.size(): " << intVec1.size() << std::endl; // 5
    std::cout << "intVec1.capacity(): " << intVec1.capacity() << std::endl; // 5
    
    std::vector<int> intVec2(10);
    std::cout << "intVec2.size(): " << intVec2.size() << std::endl; // 10
    
    std::vector<int> intVec3{10};
    std::cout << "intVec3.size(): " << intVec3.size() << std::endl; // 1
    
    std::vector<int> intVec4{5, 2023};
    std::cout << "intVec4.size(): " << intVec4.size() << std::endl; // 2

    return 0;
}
