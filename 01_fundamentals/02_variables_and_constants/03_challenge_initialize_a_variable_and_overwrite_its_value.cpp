/*
 * In this challenge, your task is to:
 * - Declare a varable: int var;
 * - Initialize var to 5000;
 * - Print the value of the var;
 * - Overwrite the value of var to 1000;
 * - Print the value of the var again in the new line.
*/

#include <iostream>

int main(){
    // Declare a varable: int var.
    int var;
    
    // Initialize var to 5000.
    var = 5000;
    
    // Print the value of the var.
    std::cout << "var: " << var << std::endl;
    
    // Overwrite the value of var to 1000
    var = 1000;
    
    // Print the value of the var again.
    std::cout << "var: " << var << std::endl;
         

    return 0;
}
