/*
 * In C++, a pointer is a variable that sotres the address of another variable.
 * Th declare a variable as a pointer, it's identifier must be preceded by as astersik *. When we use *
 * before the identifier, it indicates that the variable being declared is a pointer:
 * DataType* identifier;
 * Note we cen put astersik in three places:
 * DataType* identifier or DataType * identifier or DataType *identifier 
 *
 * It's considered a best practice to set a pointer to nullptr when it is declared, unless it is initialized
 * to some valid address.
 * It's a good practice to use ptr in a pointer's variable name. It indicates that a variable is a pointer,
 * and must be handeled differently.
 * Note: If we declare multiple pointers in the same line, we must use an asterisk before each identifier.
 *
 * To initialize a pointer, we must store the address in it. The basic syntax for storing an adddress of
 * another variable in the pointer variable is:
 * ptrVariable = &variable;
*/

#include <iostream>

int main(){

    // Declare a pointer variable ptr_num;
    int* ptr_num = nullptr;
    std::cout << "nullptr: " << ptr_num << "\n";
    
    // Declare a variable num
    int num = 7;
    
    // Store the address of variable num in ptr_num
    ptr_num = &num;
    
    std::cout << "Value of num: " << num << "\n"; // 7
    std::cout << "Value of ptr_num: " << ptr_num << "\n"; // address
    

    return 0;
}
