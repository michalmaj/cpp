/*
 * In this challenge, you are given a character. Your task is to find whether character is an 
 * upper-case alphabet, a lower-case alphabet, or a non-alphabetic character.
*/

#include <iostream>

int main(){
    char character = 'a';
    
    // Check if letter is upper-case alphabet
    if (character >= 'A' && character <= 'Z')
        std::cout << "upper-case alphabet\n";
    else if (character >= 'a' && character <= 'z')
        std::cout << "lower-case alphabet\n";
    else
        std::cout << "not an alphabet\n";

    return 0;
}
