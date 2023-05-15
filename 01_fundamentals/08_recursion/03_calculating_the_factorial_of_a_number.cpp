/*
 * The factorial of a iven number is the product of the number by all the numbers smaller than it until
 * it reaches 1.
 * Note: We can only calculate the factorial for the non-negative integers.
*/
#include <iostream>

int factorial(int n){
    if(n < 0)
        return -1;
    
    // Base case
    if(n == 1 || n == 0)
        return 1;
        
    // Recursive call
    return n * factorial(n - 1);
}

int main(){

    int n = 6;
    
    // Call factorial function in main and store the returned value in result
    int result = factorial(n);
    
    std::cout << "Factorial of " << n << " = " << result << "\n";

    return 0;
}
