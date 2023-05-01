/*
 * In this challenge, you are provided with the salaries of two people. Your task is to find the
 * person with the highest salary.
 * int salary1 = 56000; // belongs to person1
 * int salary2 = 89000; // belongs to person2
*/

#include <iostream>

int main(){
    // Initialize both variables
    int salary1 = 56000; // belongs to person1
    int salary2 = 89000; // belongs to person2
    
    std::string result = (salary1 > salary2)? "person1" : "person2";
    
    std::cout << result << "\n";


    return 0;
}
