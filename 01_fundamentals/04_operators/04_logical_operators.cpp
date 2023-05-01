/*
 * Logical operators are either used to combne two or more boolean operands or to negate the
 * results of the original boolean operands. List of logical operators available in C++:
 * https://en.cppreference.com/w/cpp/language/operator_logical
*/

#include <iostream>

int main(){
    bool operand1 = 2 > 3;
    bool operand2 = true;
    
    std::cout << std::boolalpha;
    std::cout << "Values of operands are: ";
    std::cout << "operand1: " << operand1 << ", operand2: " << operand2 << "\n";
    std::cout << "operand1 && operand2: " << (operand1 && operand2) << "\n";
    std::cout << "operand1 || operand2: " << (operand1 || operand2) << "\n";
    std::cout << "!operand2: " << (!operand1) << "\n";
    std::cout << "!operand1: " << (!operand2) << "\n";


    return 0;
}
