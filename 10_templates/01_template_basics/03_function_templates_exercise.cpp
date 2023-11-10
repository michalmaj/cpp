/*
 * Problem statement:
 * We have to implement a function which calculates 2^10 in the program.
 */

#include <iostream>

// Solution 1: Using Function Arguments
// We're using for loop to compute the power, The loop runs a total of p-1 times by multiplying the number res with n
// for every iteration.
int power_args(int n, int p){
    int res = 1;
    for(int i{0}; i < p; ++i)
        res *= n;

    return res;
}

// Solution 2: Using Template Arguments
// First, this template (primary) is called, then the PowerTemplateArgs<n, p-1>::value is executed. This expression
// instantiates recursively until the end condition is met: p is equal to 0. Now, the boundary condition is applied,
// which returns 1.
template <int n, int p>
struct PowerTemplateArgs{
    static const int value = n * PowerTemplateArgs<n, p-1>::value;
};
 template<int n>
 struct PowerTemplateArgs<n, 0>{
     static const int value = 1;
 };

 // Solution 3: Using Template Arguments and Function Arguments
 template<int p>
 int powerTemplateFunctionArgs(int n){
     return n * powerTemplateFunctionArgs<p-1>(n);
 }
 template<>
 int powerTemplateFunctionArgs<1>(int n){
     return n;
 }

int main(){
    // First solution
    std::cout << "Solution 1: Using Function Arguments: " << power_args(2, 10) << std::endl;

    // Second solution, the call PowerTemplateArgs<2, 10>::value triggers recursive calculation.
    std::cout << "Solution 2: Using Template Arguments: " << PowerTemplateArgs<2, 10>::value << std::endl;

    // Third solution
    std::cout << "Solution 3: Using Template Arguments and Function Arguments: " << powerTemplateFunctionArgs<10>(2);

    return 0;
}