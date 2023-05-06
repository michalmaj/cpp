/*
 * For dynamic allocation, we have to do the following two steps:
 *  - First, allocate the dynamic space.
 *  - Then, store the starting address of the dynamic space in the pointer.
 *
 * The unary operator new allocates memory in bytes during the run time from the free store.
 * If memory is available on the free store, the new operator will reserve that memory and return its
 * starting address. The basic syntax for getting memory during the run-time is given below:
 * new datatype;
 *
 * To store the starting address returned by the new operator, we use pointers. The basix syntax is:
 * datapyte* pointer = new datatype
 *
 * The compiler automatically deallocates the static space when it s not used anymore. Since dynamically
 * allocated memory is managed by a programmer, when dynamically allocated space is not required anymore,
 * we must free it.
 * The delete operator allows us to free the dynamically allocated space. The basic syntax for releasing
 * the memory that the pointer is pointing to is given below:
 * delete pointer;
 * Note: It's a good practice the set the pointer to nullptr after deallocation, unless we are pointng to
 * some other valid target.
*/

#include <iostream>

int main(){
    // Declare pointer and initialize to nullptr.
    int* ptr = nullptr;
    
    // Store the starting address of dynamically reserved 4 bytes in ptr.
    ptr = new int;
    
    // Store value in dynamic space using dereference operator
    *ptr = 99;
    
    // Print value and memory address
    std::cout << "Value: " << *ptr << ", address: " << ptr << "\n";
    
    // Free the space pointed by pointer ptr;
    delete ptr;
    ptr = nullptr;


    return 0;
}
