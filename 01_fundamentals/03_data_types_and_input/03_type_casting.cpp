/*
 * Type-casting is a way to convert the value of one data type to another data type.
 * Type-casting has two types:
 *  1. Implicit casting.
 *  2. Explicit casting.
 *
 * We should always do type-casting from smaller to larger data types. Otherwise, we can
 * lose our data. In first example below we are loosing the information after the decimal
 * point.
 * 
 * In implicit casting, the compiler automatically converts one data type to another. For
 * example, f we store a floating-point value into a variable of integer type, the compiler
 * will convert the float value into int without any user intervention.
 *
 * In explicit casting, the user manually converts one data type to another. The basiic syntax
 * for explicit type casting in C++ is:
 *  static_cast<data_type>(variable_name)
 * It is also possible to use C-style casting:
 *  (data_type)variable_name
*/

#include <iostream>

int main(){
    // Put floating-point value in variable of type int.
    int int_value = 13.7; // Inplicit casting. Note: we are losing some data.
    
    // Show the result
    std::cout << "int_value: " << int_value << std::endl;
    
    // Declare and initialize two variables of char data type
    char char1= 'A';
    char char2 = 'B';
    
    // Declare two variables of int type.
    int ascii1;
    int ascii2;
    
    // Converts char data type into int explicitly
    ascii1 = static_cast<int>(char1); // Safer casting style.
    ascii2 = (int)char2; // C-style casting.
    
    std::cout << "After casting ascii1: " << ascii1 << std::endl; 
    std::cout << "After casting ascii2: " << ascii2 << std::endl; 


    return 0;
}
