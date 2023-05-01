/*
 * In C++, we can use the else-if statement t check multiple condition in a program.
*/

#include <iostream>

int main(){
    // Initialize a variable
    int money = 6;
    
    // if block
    if (money >= 20)
        std::cout << "You have 20 or more euros\n";
    // else-f block
    else if (money >= 10)
        std::cout << "You have less than 20 euros but more than 9 euros\n";
    else if (money >= 5)
        std::cout << "You have less thsn 10 euros but more than 4 euros\n";
    // else block
    else
        std::cout << "You have less than 5 euros\n";



    return 0;
}
