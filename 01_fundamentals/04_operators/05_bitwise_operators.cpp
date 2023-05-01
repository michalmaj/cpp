/*
 * A bitwise operator performs bit by bit processing on the operands.
 * Bitwise operators operate on binary numbers. They convert operands in decimal form into
 * binary form, perform the particualr bitwise operation, and then retun the result after
 * converting the number back into decimal form. List of bitwise operators:
 * https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
 * 
 * Bitwise AND: if the corresponding bits in both the operands is 1, it returns 1. Otherwise,
 * it returns 0.
 *
 * Bitwise OR: if the corresponding bit in at least of the operands is 1, it returns 1.
 * Otherwis, it returns 0.
 *
 * Bitwise XOR: if the corresponding bits in both the operands are opposite, it returns 1.
 * Otehrwise, it returns 0.
 *
 * Right-shifting an operand1 >> operand2 is equivalent to dividing operand1 by (2^operand2).
 * Example: 2 >> 1 = 2 / (2^1) = 1
 *
 * Left-shifting an operand1 << operand2 is equivalent to multilpying operand1 by (2^operand2).
 * Example: 2 << 1 = 2 * (2^1) = 4
 *
 *The tilde operator ~ is a bitwise complement operator that nverse all the bits in a number.
 *
 * For printing purpose we will be using a std::bitset class:
 * https://en.cppreference.com/w/cpp/utility/bitset
*/

#include <iostream>
#include <bitset>

int main(){
    // Bitwise AND, OR, XOR
    int op1 = 3;
    int op2 = 2;
    
    // Print value and bit representation of our operands
    std::cout << "Bitwise AND, OR, XOR:\n";
    std::cout << "op1: " << op1 << ", bit representation: " << (std::bitset<8>(op1)) << "\n";
    std::cout << "op2: " << op2 << ", bit representation: " << (std::bitset<8>(op2)) << "\n";
    std::cout << "op1 & op2 decimal: " << (op1 & op2) << ", in bits: " << (std::bitset<8>(op1 & op2)) << "\n";
    std::cout << "op1 | op2 decimal: " << (op1 | op2) << ", in bits: " << (std::bitset<8>(op1 | op2)) << "\n";
    std::cout << "op1 ^ op2 decimal: " << (op1 ^ op2) << ", in bits: " << (std::bitset<8>(op1 ^ op2)) << "\n";
    
    // Right-shift and left-shft.
    int op3 = 2;
    int op4 = 1;
    
    // Print value and bit representation
    std::cout << "\nRight-shift and left-shft:\n";
    std::cout << "op3: " << op3 << ", bit representation: " << (std::bitset<8>(op3)) << "\n";
    std::cout << "op4: " << op4 << ", bit representation: " << (std::bitset<8>(op4)) << "\n";
    std::cout << "op3 >> op4 decimal: " << (op3 >> op4) << ", in bits: " << (std::bitset<8>(op3 >> op4)) << "\n";
    std::cout << "op3 << op4 decimal: " << (op3 << op4) << ", in bits: " << (std::bitset<8>(op3 << op4)) << "\n";
        
    // ~ operator
    int op5 = 5;
    
    // Print value and bit representation of our operand
    std::cout << "\n~ operator:\n";
    std::cout << "op5: " << op5 << ", bit representation: " << (std::bitset<8>(op5)) << "\n";
    std::cout << "~op5: " << ~op5 << ", bit representation: " << (std::bitset<8>(~op5)) << "\n";
    

    return 0;
}
