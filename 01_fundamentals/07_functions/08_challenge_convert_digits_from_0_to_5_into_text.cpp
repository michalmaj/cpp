/*
 * Your task is to write a function digit_text. In the function parameter, you will pass the
 * value of type int, and it will return a string output. Your function should:
 *  - Convert a dgit from 0 to 5 into words;
 *  - If a number is other than 0 to 5, your program should return an invalid number;
 *  - Store your result in the variable os type string.
*/

#include <iostream>

std::string digit_text(int number){
    switch (number){
    case 0:
        return "zero";
    case 1:
        return "one";
    case 2:
        return "two";
    case 3:
        return "three";
    case 4:
        return "four";
    case 5:
        return "five";
    default:
        return "invalid number";
    }
}

int main(){
    std::string result = digit_text(5);
    std::cout << result << "\n";

    return 0;
}
