/*
 * The dereference operator * is a unary operator. It gives the value of the variable to which the pointer
 * is pointing. This process is known as dereferencing a pointer.
 * Note: Trying to dereference an uninitialized or null pointer generates an error.
*/

#include <iostream>

int main(){
    int num = 7;
    int* ptr_num = &num;
    
    std::cout << "num value: " << num << "\n";
    std::cout << "ptr_num value: " << ptr_num << "\n";
    std::cout << "Dereference ptr_num: " << *ptr_num << "\n";



    return 0;
}
