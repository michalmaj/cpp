/*
 * Input operator is the exact opposite of output operation. In input operation, we take data
 * from the user and store it in the memory.
 *
 * The basic syntax for taking input from the user is given below:
 *  std::cin >> variable_name;
 * We use a std::cin in combination with the extraction operator >> to take input from the user.
 *
 * std::cin is connected to the keyboard. It takes anything coming from the keyboard and sends
 * it to the extraction operator.
 *
 * >> is called the extraction or input operator. It takes content from std:cin and stores it
 * into the variable to its right.
 *
 * In C++, we use std::cin to take user input from the keyboard. TO use the input later, we must
 * store it somewhere. We use variables to store input taken from the user.
*/

#include <iostream>

int main(){
    // Declare variable
    float number;
    
    // Display text
    std::cout << "Enter your number: ";
    
    // Get input from the user.
    std::cin >> number;

    // Display entered number
    std::cout << "Your number is: " << number << std::endl;

    return 0;
}
