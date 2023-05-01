/*
 * In this challenge, you are given a weekday number. Your task is to display the corresponding
 * day name to the console using the switch statement.
*/

#include <iostream>

int main(){
    int number;
    std::cout << "Enter number to convert to day: ";
    std::cin >> number;
    
    switch (number){
    case 1:
        std::cout << "Monday\n";
        break;       
    case 2:
        std::cout << "Tuesday\n";
        break;
    case 3:
        std::cout << "Wednesday\n";
        break;
    case 4:
        std::cout << "Thursday\n";
        break;
    case 5:
        std::cout << "Friday\n";
        break;
    case 6:
        std::cout << "Saturday\n";
        break;
    case 7:
        std::cout << "Sunday\n";
        break;
    default:
        std::cout << "Invalid input\n";
        break;
    }



    return 0;
}
