/*
 * The assignment operator takes the value o its right-hand side and assigns it to the operand
 * on the left-hand side.
 * 
 * The compound assignment operator is used to perform an operation and then assign the result
 * to the operand on the left-hand side. Link to the list of compound assignemnt operators:
 * https://www.tutorialspoint.com/Compound-Assignment-Operators-in-Cplusplus
*/

#include <iostream>

int main(){
    // Assign value to the operands
    int operand1 = 50;
    float operand2 = 26.f;
    double operand3 = 78;
    bool operand4 = true;
    char operand5 = 'A';
    std::string operand6 = "Hello";
    
    // Print value of the operands
    std::cout << "operand1: " << operand1 << "\n";
    std::cout << "operand2: " << operand2 << "\n";
    std::cout << "operand3: " << operand3 << "\n";
    std::cout << "operand4: " << operand4 << "\n";
    std::cout << "operand5: " << operand5 << "\n";
    std::cout << "operand6: " << operand6 << "\n";
    
    // Consider two operands of type int. The value of op1 is 50 and the value of op2 is 26.
    int op1 = 50;
    int op2 = 26;
    std::cout << "Before using compound assignment operator:\n";
    std::cout << "op1: " << op1 << "\n";
    op1 += op2;
    std::cout << "After using compound assignment operator:\n";
    std::cout << "op1: " << op1 << "\n";

    return 0;
}
