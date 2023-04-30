/*
 * Constants are similar to variables except that we can't change their value during 
 * the code execution.
 *
 * In C++, we can use the const keyword to declare a constant. The basic syntax is:
 *  const constant_datatype constant_name = constant_vale;
*/

#include <iostream>

int main(){
    const int number = 20;
    std::cout << "Number: " << number << std::endl;
    
    // Uncommenting the following line will result in a compiler error.
    // numer = 10;

    return 0;
}
