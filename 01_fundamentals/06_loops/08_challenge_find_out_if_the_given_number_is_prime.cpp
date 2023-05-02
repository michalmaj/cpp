/*
 * Read number from keyboard and find whether the given number is prime or not.
*/

#include <iostream>

int main(){
    // Create bool varaible to store information f variable is prime or not
    bool is_prime = true;
    // Declare variable to store a namber
    int number;
    std::cout << "Enter number to check if it's a prime number: ";
    std::cin >> number;
    
    if(number < 2)
        is_prime = false;
    
    for(int i = 2; i <= number / 2; ++i){
        if (number == 2)
            break;
        if (number % i == 0){
            is_prime = false;
            break;
        }
    }
    
    std::cout << ((is_prime)? "prime" : "not prime") << "\n";


    return 0;
}
