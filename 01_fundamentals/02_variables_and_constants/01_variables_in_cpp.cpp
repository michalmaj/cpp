/*
 * In terms pf programming language, a variable is a location in the
 * computer's memory where we can store data. The value of this data can be 
 * changed during te execution of a program. Each variable has a unique and 
 * meaningful name which is known as an identifier.
 *
 * A variable declaration means that we want the compiler to reserve a space
 * for data with the given name and type. The basic syntax for declaring a
 * variable   in C++ is:
 *  variable_datatype variable_name;
 * 
 * Variable initialization means to actually store value in the reserved space.
 * The basic syntax for initializing a variable in C++ is:
 *  variable_datatype variable_name = variable_value;
*/

#include <iostream>

int main(){
    // Declare variable
    int current_amount; // Declaration without initialization
    
    // Initialize variable
    current_amount = 100;
    
    // Print the value
    std::cout << "Current amonut: " << current_amount << std::endl;
    
    // Update the value
    current_amount = 120;
    
    // Print the value
    std::cout << "Current amonut: " << current_amount << std::endl;

    return 0;
}
