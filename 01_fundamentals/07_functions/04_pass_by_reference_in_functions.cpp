/*
 * In pass by reference, when we call a function, we pass the address of the actual parameters
 * to the formal parameters in the function.
 * In pass by reference, the actual and formal parameters refer to the same memory location. Any
 * changes made in the formal parameters inside the function affect the values of actual
 * parameters in the main function.
*/

#include <iostream>

void passByReference(int& number){
    number = number * 10;
    std::cout << "Value of number inside the function: " << number << "\n";
}

int main(){
    // Declare and initialize varible
    int number = 10;
    
    std::cout << "Value of number before function calling: " << number << "\n";
    
    // Call our function
    passByReference(number);
    
    std::cout << "Value of number after function calling: " << number << "\n";

    return 0;
}
