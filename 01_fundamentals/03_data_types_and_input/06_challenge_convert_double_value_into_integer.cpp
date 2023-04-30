/*
 * In ths challenge, your task is to convert the variable value from double (double_value) 
 * to an int (int_value).
 * Initialized variable looks like:
 *  double double_value = 70.986;
*/

#include <iostream>

int main(){
    // Declare and initialize the double_value variable
    double double_value = 70.986;
    
    // Declare and initialize int_value, value cast from double_value.
    int int_value = static_cast<int>(double_value);

    // Print value:
    std::cout << "int_value = " << int_value << std::endl;

    return 0;
}
