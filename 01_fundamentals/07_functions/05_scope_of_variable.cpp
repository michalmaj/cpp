/*
 * The scope of a variable defines which part of the program that particular variables is
 * accessible in. In C++, the variable can be either of these two:
 *  1. Local variable.
 *  2. Global variable.
 *
 * Local variable is only accessible within the bloc in which it is declared. Block is a section
 * of code enclosed inside the curly braces. A block can be a function, loop, or conditional
 * statements. These variables are created when compiler executes that particular block and 
 * destroyed when compiler exits that blck.
 *
 * Global variables can be accessed from the point they are declared to the end of the program.
 * They are declared at the very start of the program before defining any function.
 *
 * Note: If two variables with the same name are declared twice withn the same scope, the
 * compiler will generate an error.
*/

#include <iostream>

int global = 3;

void function(){
    int local = 10;
    std::cout << "Global variable in function: " << global << "\n"; 
}

int main(){
    int local = 20;
    
    std::cout << "Global variable in main function: " << global << "\n";
    
    // Call function
    function();
    
    // Shadow global variable
    int global = 9;
    std::cout << "Shadowed global variable: " << global << "\n";


    return 0;
}
