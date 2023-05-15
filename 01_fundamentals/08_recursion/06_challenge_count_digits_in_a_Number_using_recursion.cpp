/*
 * Your task is to write a recursive function count_digits. In the function parameter, you will pass the
 * value of type int, and function will return an int value in the output.
 * Your function should count the total number of digits in a number and return the number of digits in
 * output. Your solution should work for both positive and negative values, including 0.
*/
#include <iostream>

int count_digits(int number){
int i = 0;
    // Base case
    if(number / 10 == 0)
        return 1;

    // Resursive case
    return 1 + count_digits(number / 10);
}

int main(){
    // Initialize number
    int number = 4325;
    
    int result = count_digits(number);
    
    std::cout << "Number of digits in number " << number << " = " << result << std::endl;
    return 0;
}
