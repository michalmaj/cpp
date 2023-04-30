/*
 * Data type modifiers are used wth primitive data types to change the meaning of predefined
 * data types according to the situation.
 *
 * C++ supports the following data type modifiers:
 *  - long;
 *  - short;
 *  - unsigned;
 *  - signed;
 * We can use data type modifiers with int, double and char data types.
 *
 * long is used to increase the length of data type. We can use long with int and double data
 * types.
 * 
 * short decreases the available length of a data type. We can use short with an int data type.
 *
 * unsgned allows us to store postive values only. We can use unsigned with char and int data
 * types. With unsigned int, we can store any value from 0 to 4294967295. With unsigned char,
 * we can store any value from 0 to 255.
 *
 * signed allows us to store both positive and negative values. We can use signed with char and
 * int data types. With signed int, we can store any value from -2,147,483,648 to
 * 2,147,483,647. With signed char, we can store any value from -128 to 127.
 */

#include <iostream>

int main(){
    // Declare and initialize int and long int varables
    int integer = 2147483649; // Overflow
    long int long_integer = 2147483649;
    
    // Display variables
    std::cout << "integer: " << integer << ", size: " << sizeof(integer) << std::endl;
    std::cout << "long integer: " << long_integer << ", size: " << sizeof(long_integer) << std::endl; 
    
    // Overwrite integer value and declare and initialize short int variable
    integer = 32768;
    short int short_integer = 32768; // Overflow
    
     // Display variables
    std::cout << "integer: " << integer << ", size: " << sizeof(integer) << std::endl;
    std::cout << "short integer: " << short_integer << ", size: " << sizeof(short_integer) << std::endl; 
    
    // Overwrite integer value and declare and initialize unsigned int variable.
    integer = -10;
    unsigned int unsigned_integer = -10; // Underflow
    
    // Display variables
    std::cout << "integer: " << integer << ", size: " << sizeof(integer) << std::endl;
    std::cout << "unsigned integer: " << unsigned_integer << ", size: " << sizeof(unsigned_integer) << std::endl;
    
    // Declare and initialize char and unsigned char variables
    char character = 'A';
    unsigned char unsigned_character = 'B';
    
    // Display variables
    std::cout << "character: " << character << ", size: " << sizeof(character) << std::endl;
    std::cout << "unsigned character: " << unsigned_character << ", size: " << sizeof(unsigned_character) << std::endl;
    

    return 0;
}
