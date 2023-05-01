/*
 * The conditional operator evaluates the given condition and returns the result accordingly.
 * The conditional operator operates on three operands. Therefore, it is known as the ternary
 * operator.
*/

#include <iostream>

int main(){
    // Initialize variable money
    int money = 10;
    
    // Declare variable result
    std::string result;
    
    // Ternary operator
    result = (money >= 20)? "You have 20 euros or more" : "You have less than 20 euros";
    
    // Print the result
    std::cout << result << "\n";



    return 0;
}
