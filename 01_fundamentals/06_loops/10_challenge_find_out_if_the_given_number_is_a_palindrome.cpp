/*
 * A number is a palindrome if it reads the same backward as forward, e.g., 1221
*/

#include <iostream>

int main(){
    // Declare a varaible to store number to check if it is a palindrome
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    int n = number;
    int rev = 0;
    int digit = 0;
    
    while(number != 0){
        digit = number % 10;
        rev = rev * 10 + digit;
        number /= 10;
    }
    
    std::cout << ((n==rev)? "is palindrome" : "not a palindrome") << "\n";


    return 0;
}
