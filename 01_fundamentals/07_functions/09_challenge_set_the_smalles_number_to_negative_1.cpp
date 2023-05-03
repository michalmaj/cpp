/*
 * Your task is to write a function minimum. In the function parameter, you will pass two values
 * of type int by reference, and function will set the smallest number of the two to -1. If
 * both equal set first parameter to -1.
*/

#include <iostream>

void minimum(int& number1, int& number2){
    (number1 <= number2)? number1 = -1 : number2 = -1;
}

int main(){

    int number1 = 6;
    int number2 = 2;
    std::cout << "Values before calling function: " << number1 << " " << number2 << "\n";
    
    minimum(number1, number2);
    std::cout << "Values after calling function: " << number1 << " " << number2 << "\n";
    
    return 0;
}
