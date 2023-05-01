/*
 * In the if-else statement, when the condition in an if statement evaluates to false, the 
 * compiler executes the code inside else block.
*/

#include <iostream>

int main(){
    // initialize varaible
    int money = 10;
    
    // if condition
    if (money >= 20) // Without curly brackets only first line below if will be executed
        std::cout << "You have 20 or more euros\n";
    else
        std::cout << "You have less than 20 euros\n";


    return 0;
}
