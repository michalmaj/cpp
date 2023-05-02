/*
 * Read number from keyboard and convert it into a binary number.
*/

#include <iostream>

int main(){
    // Declare varabl to store binary number
    int binary = 0;
    // Declare variable to store number to convert.
    int decimal;
    std::cout << "Enter decimal number: ";
    std::cin >> decimal;
    
    int multiplier = 1;
    
    while(decimal > 0){
        binary += (decimal % 2) * multiplier;
        decimal /= 2;
        multiplier *= 10;
    }
    std::cout << "binary = " << binary << "\n";


    return 0;
}
