/*
 * We know that when we declare a variable, the compiler allocates space someplace in the memory location.
 * What if we want to know the memory address where the variable has been allocated?
 * For this, we will use the address-of operator& before the identifier to access the address of the
 * variable. The address-of operator (&) is a unary operator. It is used to extract the memory address of 
 * the variable: &identifier.
*/

#include <iostream>

int main(){
    // Declre and initialize variable number
    int number = 20;

    // Print the memory address in which value of number is stored
    std::cout << "Number Address: " << &number << ", Number Value: " << number << "\n";

    return 0;
}
