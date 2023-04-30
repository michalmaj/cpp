/*
 * Write a code to swap the values of the two variables. We have two initialized variables
 * var1 = 1 and var2 = 2. Your task is to use var1 and var2 and swap their values.
*/

#include <iostream>

int main(){
    int var1 = 1;
    int var2 = 2;
    int temp; // We need extra variable to store data from var1
    std::cout << "Before swap:\n";
    std::cout << "var1: " << var1 << ", var2: " << var2 << std::endl;  
     
    // Logic
    temp = var1; // Value from var1 is stored in temp variable
    var1 = var2; // From now var1 holds value from var2
    var2 = temp; // We put value from temp into var2
    std::cout << "After swap:\n";
    std::cout << "var1: " << var1 << ", var2: " << var2 << std::endl; 

    return 0;
}
