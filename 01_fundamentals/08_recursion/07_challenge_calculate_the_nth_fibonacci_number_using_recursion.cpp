/*
 * In this challenge, your task is to calculate the nth Fibonacci number in the Fibonacci series.
 * You have to write a recursive function fibonacci. In the function parameter, you will pass the value of
 * type int, and the function will return a value of type int. It is assumed that only a non-negative value
 * for the parameter n will be used.
 * Fibonacci series starts with 0 and 1. Each number in the Fibonacci series is the sum of its two previous
 * Fibonnaci numbers. E.g. fibonnaci(0) = 0, fibonacci(1) = 1
*/
#include <iostream>

int fibonacci(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
        
    return fibonacci(n - 2) + fibonacci(n - 1);
    
}

int main(){
    // Initialize variable n
    int n = 4;
    // Declare variable result
    int result;
    // Call fibonacci function in main and store its output in result
    result = fibonacci(4);
    // Print value of result
    std::cout << n << "th Fibonacci number = " << result << "\n";

    return 0;
}
