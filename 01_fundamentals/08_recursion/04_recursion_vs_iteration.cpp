/*
 * We can implement a recursive solution iteratively. Let's write a program to calculate the factorial
 * of a number using a loop. In the iterative solution, we are not calling the same problem with a
 * simpler version; instead, we are using the counter variable and we keep incrementing it until the given
 * condition is true.
 *
 * The following are the differences between recursion and iteration:
 *  - In the computer language, iteration allows you to repeat a particular set of instructions until the
 *    specified condition is met. The recursive function allows you to keep calling itself in the function
 *    body until some condition is met.
 *  - The sole purpose of iteration and recursion is to achieve repetition. Loops achieve repetition through
 *    the repetitive structure, whereas recursion achieves repetition through repetetive function calls.
 *  - Iteration terminates when loop condition fails. On the other hand, recursion terminates when the
 *    the base condition evaluates to true.
 *  - Iteration happens inside the same function, which is why it takes less memory. In the recursive
 *    function, there is the overhead of function calls makes our program slow and consumes more memory.
 *  - In iteration, our code size is very large. Meanwhile, recursion helps to write shorter code.
 *  - Infinite loop will stop further execution of the program but do not lead to system crash. Infinite
 *    recursive calls, will result in a CPU crash because of memory overflow.
*/
#include <iostream>

// Iterative factorial function
int factorial(int n){
    int fact = 1;
    if(n == 0)
        fact = 1;
    if(n < 0)
        fact = -1;
        
    for(int counter = 1; counter <= n; counter++)
        fact = fact * counter;
        
    return fact;
}

int main(){
    int n = 6;
    
    int result = factorial(n);
    
    std::cout << "Factorial of " << n << " = " << result << "\n";

    return 0;
}
