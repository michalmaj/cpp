/*
 * An std::unique_ptr automatically and exclusively manages the lifetime of its resource accordind to the
 * RAII idiom.
 * Resource Acquisition Is Initialization, short RAII, stands for a popular technique in C++, in which the
 * resource acquisition and release are bound to the lifetime of an object. This means for the smart pointer
 * that the memory is allocated in the constructor and deallocated in the destructor. YWe can use this 
 * technique in C++ because the destructor is called when the object goes out of scope.
 *
 * std::unique_ptr should be our first choice since it functions without memory or performance overhead.
 * std::unique_ptr exclusively controls its resource. It automatically releases the resuorce if it goes
 * out of scope. No copy sematics are required, and it can be used is containers and algoriths of the 
 * Standard Template Library. std::unique_ptr is as cheap and fast as a raw pointer when no special
 * delete function is used. The std::unique_ptr:
 *  - can be instantiated with and without a resource.
 *  - manages the life cycle of a single object or an array of objects.
 *  - transparently offers the interference of the undelying resource.
 *  - can be parametrized with its own deleter function.
 *  - can be moved (move semantics).
 *  - can be creted with the helper funtion std::make_unique (since C++14).
 * Note: Always use std::make_unique, it guarantees that no memory leak will occur.
 *
 * These are the methods of std::unique_ptr:
 *  - get - returns a pointer to the resource.
 *  - get_deleter - returns the delete function.
 *  - release - returns a pointer to the resource and releases it.
 *  - reset - resets the resource.
 *  - swap - swap the resources.
 *
 * Documentation: https://en.cppreference.com/w/cpp/memory/unique_ptr
*/

#include <iostream>
#include <memory> // Head for smart pointers

int main(){
    std::unique_ptr<int> up1(new int(99)); // Create using new 
    std::unique_ptr<int> up2 = std::make_unique<int>(77); // Create using std::make_unique
    
    std::cout << "up1: " << *up1 << "\n";
    std::cout << "up2: " << *up2 << "\n";
    
    // Unique pointer can't be copied
    // std::unique_ptr<int> up_copy = up1; // Compiler Error
    
    // But can be moved to another unique_ptr
    std::unique_ptr<int> up3 = std::move(up1);
    std::cout << "up3: " << *up3 << "\n";


    return 0;
}
