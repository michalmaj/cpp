/*
 * A relational operator compares the value of two operands. The output of a relational operator
 * is a bool data type. List of relational operators available in C++:
 * https://en.cppreference.com/w/cpp/language/operator_comparison
 *
 * In C++, we can also compare float, string, and char data types using relational operators.
 * When we apply relational operators to the operands of type char, the compiler will compare
 * the ASCII values of the character.
 *
 * Note: Writing relational expression without parentheses in the print statement will generate
 * a compiler error.
*/

#include <iostream>

int main(){
    // Compare int values.
    int operand1 = 50;
    int operand2 = 26;
    
    std::cout << "operand1: " << operand1 << ", operand2: " << operand2 << "\n";
    
    std::cout << std::boolalpha; // Shows true/false instead of 1/0
    std::cout << "Is operand1 less than operand2? " << (operand1 < operand2) << "\n";
    std::cout << "Is operand1 less than or equal operand2? " << (operand1 <= operand2) << "\n";
    std::cout << "Is operand1 greater than operand2? " << (operand1 > operand2) << "\n";
    std::cout << "Is operand1 greater than or equal operand2? " << (operand1 >= operand2) << "\n";
    std::cout << "Is operand1 is equal to operand2? " << (operand1 == operand2) << "\n";
    std::cout << "Is operand1 is not equal to operand2? " << (operand1 != operand2) << "\n";

    // Compare string values (lexicographically comparison).
    std::string str1 = "Microsoft";
    std::string str2 = "Apple";
    
    std::cout << "Is str1 is greater than str2? " << (str1 > str2) << "\n";

    return 0;
}
