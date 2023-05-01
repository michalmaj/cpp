/*
 * In this challenge, you are given character that stored in a varable character. Your task is
 * to write a code that makes the same variable, character, now store the character preceding
 * the one originally sotre in it. For example, if the variable stored C orginally, your code
 * should make t store B
*/

#include <iostream>

int main(){
    char character = 'B';
    std::cout << "Character before operation: " << character << "\n";
    
    character -= 1;
    std::cout << "Character after operation: " << character << "\n";


    return 0;
}
