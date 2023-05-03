/*
 * In pass by value, when we call a function, we pass the copy of the actual parameters to the
 * formal parameters in the function.
*/

#include <iostream>

void passByValue(int number){
    number = number * 10;
    std::cout << "Value of number inside the function: " << number << "\n";
}

int main(){
    // Declare and initialize variable
    int number = 10;
    
    std::cout << "Vale of number before function call: " << number << "\n";
    
    // Call our function
    passByValue(number);
    
    std::cout << "Vale of number after function call: " << number << "\n";



    return 0;
}
