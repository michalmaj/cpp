/*
 * The integer data type comprises all positive and negative whole numbers. We use the 
 * int keyword to define the integer data type. A variable of int type is allocated typically
 * 4 bytes of memory. It can store asy valye fro -2^31 to (2^31) - 1.
 *
 * The floating-point data type contains a number with a fractional part. We use the float
 * keyword to define the floating-point data type. A variable of a float type is allocated
 * typically 4 bytes of memory. It can store any value in the range of +-3.40*10^(+-38).
 *
 * The double data type contains the number with the fractional part. We use the double
 * keyword to define the double data type. A variable of double type is allocated 8 bytes
 * of memory. It can store any value in the range of +-1.79*10^(+-308).
 * 
 * The precision of a floating-point number is the number of digits that can be stored after
 * a decimal point. A float can store 7 digits after a decimal point precisely. Whereas, double
 * can store 15 digits after a decimal point precisely. It is recommended to use double for
 * floating-point values.
 *
 * The character data type contans a single character from ASCII set. WE use the char keyword
 * to define the character data type. A variable of char type is allocated 1 byte of memory.
 * It can store value from -2^7 to (2^7) - 1. A char value is always written in single
 * quotation marks.
 * ASCII table: https://www.asciitable.com/
 *
 * The boolean data type stores a logical value. It can store true and false. We can also use 1
 * to represents true and 0 to represents false. We use the bool keyword to define the boolean
 * data type. A variable of bool type is allocated 1 byte of memory.
 *
 * Note: chars and bools are also stored as numbers.
*/

#include <iostream>

int main(){
    // Create variable of type int, float and double
    int int_number = 10;
    float float_number = 10.5f;
    double double_number = 10.5;
    
    // Prints value and size of variable.
    // We can check size of a variable or type using sizeof() function
    std::cout << "int: " << int_number << ", size: " << sizeof(int) << std::endl;   
    std::cout << "float: " << float_number << ", size: " << sizeof(float) << std::endl;   
    std::cout << "double: " << double_number << ", size: " << sizeof(double) << std::endl;  
    
    // Create variable to store char and bool data types.
    char character = 'A';
    bool boolean = true;
    
    // Prints value and size of variables.
    std::cout << "char: " << character << ", size: " << sizeof(char) << std::endl;
        std::cout << "bool: " << boolean << ", size: " << sizeof(bool) << std::endl;
    
    


    return 0;
}
