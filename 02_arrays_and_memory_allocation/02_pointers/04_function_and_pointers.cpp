/*
 * We discussed the following ways of passing actual parameters to the formal parameters in the function:
 *  1. Pass by value.
 *  2. Pass by reference.
 * However, ther is another way to pass arguments to the function that is passed by reference with a pointer
 * parameter. The functon ponter parameter recieves the address of the parameter. Then, it uses the
 * dereference operator to access the value of the variable.
*/

#include <iostream>

void passByPointer(int* number){
    // Multiply the number by 10
    *number *= 10;
    std::cout << "Value of number inside the function: " << *number
    << ", address stored by pointer: " << number << "\n";
}

int main(){

    int num = 101;
    std::cout << "Value number before function call: " << num 
    << ", address of the variable: " << &num << "\n";
    
    // Call our function
    passByPointer(&num); // Note: Pass by reference
    
    std::cout << "Value number after function call: " << num 
    << ", address of the variable: " << &num << "\n";


    return 0;
}
