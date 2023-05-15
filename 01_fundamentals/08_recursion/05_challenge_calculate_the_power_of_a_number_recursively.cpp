/*
 * Your task is to write a recursive function power. In the function parameter, you wll pass base and the
 * exponent of type int and the function will return an int value in the output. t is assumed that only a
 * non-negative value for the exponent will be used.
*/
#include <iostream>

int power(int base, int exponent){
// Base case
    if(exponent == 0)
        return 1;
        
    // Recursive case
    return base * power(base, exponent - 1);
}

int main(){
    // Initialize base and exponenet
    int base = 2;
    int exponent = 4;
    
    // Call power function and store the returned value in result
    int result = power(base, exponent);

    std::cout << base << " raised to power " << exponent << " = " << result << "\n";

    return 0;
}
