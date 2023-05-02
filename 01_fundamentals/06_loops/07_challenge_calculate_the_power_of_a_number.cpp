/*
 * You are given base and exponent. Your task is to calculate the power of the number and store
 * it in variable result.
 * int base = 2;
 * int exponent = 3;
*/

#include <iostream>

int main(){
    int base = 2;
    int exponent = 3;
    int result = 1;
    
    for(int i = 1; i <= exponent; ++i)
        result *= base;
    
    std::cout << "Result: " << result << "\n";

    return 0;
}
