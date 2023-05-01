/*
 * The if statement instructs a compiler to execute a particular block of code when the
 * condtion evaluates to true.
 * In C++, a zero or null value is considered false, and non-zero values are considered true.
*/

#include <iostream>

int main(){
    // Initialize money variable
    int money = 21; // Change this to number below 20, and program won't print any message
    
    // Check condition
    if (money >= 20){
        // If condition above evaluates to true (we have 20 euros or more).
        std::cout << "You have more than 20 euros\n";
    }



    return 0;
}
