/*
 * Arithmetic operators are used to perform numeric operations on operands. List of arithmetic
 * operators is available here: https://www.w3schools.com/cpp/cpp_operators.asp
 *
 * Watch out of / operator. All operators in C++ show the same results that an ordinary
 * calculatorwould show, except for the division operator. In the example below if we put 50/26
 * in a calculator, it returns 1.92307692308 is output. However, our C++ program is returning 1.
 * So why does the C++ division operator show a result different than that of the calculator's
 * division operator?
 The reason is that the data type of our operands is int, which means that our ouptut is also
 * of type int. Therefore, C++ only gives you the whole number part of the quotient, excludng
 * the remainder to keep the type consistent. If we want a quotient with a fractional part,
 * use the float or double data type operands.
 * Note: Using a mod operator % with floating-point operands generates an error.
*/

#include <iostream>

int main(){
    // Example with 2 int operands
    // Declare and initialize variables
    int int_operand1 = 50;
    int int_operand2 = 26;
    
    // Print value of int_operand1 and int_operand2
    std::cout << "int_operand1: " << int_operand1 << "\n";
    std::cout << "int_operand2: " << int_operand2 << "\n";
    
    // Perform some operations:
    // Addition
    std::cout << "Addition: " << int_operand1 + int_operand2 << "\n";
    
    // Subtraction
    std::cout << "Subtraction: " << int_operand1 - int_operand2 << "\n";
    
    // Multiplication
    std::cout << "Multiplication: " << int_operand1 * int_operand2 << "\n";
    
    // Division
    std::cout << "Division: " << int_operand1 / int_operand2 << "\n";
    
    // Modulus
    std::cout << "Modulus: " << int_operand1 % int_operand2 << "\n";
    
    // Example with 2 float operands
    // Declare and initialize variables
    float float_operand1 = 50.0f;
    float float_operand2 = 26.0f;
    
    // Print value of int_operand1 and int_operand2
    std::cout << "float_operand1: " << float_operand1 << "\n";
    std::cout << "float_operand2: " << float_operand2 << "\n";
    
    // Perform some operations:
    // Addition
    std::cout << "Addition: " << float_operand1 + float_operand2 << "\n";
    
    // Subtraction
    std::cout << "Subtraction: " << float_operand1 - float_operand2 << "\n";
    
    // Multiplication
    std::cout << "Multiplication: " << float_operand1 * float_operand2 << "\n";
    
    // Division
    std::cout << "Division: " << float_operand1 / float_operand2 << "\n";
    
    // Modulus - won't work with floating-point data
    // std::cout << "Modulus: " << int_operand1 % int_operand2 << "\n";
    

    return 0;
}
