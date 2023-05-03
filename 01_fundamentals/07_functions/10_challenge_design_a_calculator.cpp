/*
 * The aim of ths challenge is to design a calculator that takes operands in its input and 
 * performs one of the following operations on them:
 *  - Addition;
 *  - Subtraction;
 *  - Multiplication;
 *  - Division.
 *
 * You have to write a function test that takes two values of type double and one of type char
 * in its input parameters:
 *  double test(double, char, double);
*/

#include <iostream>

double test(double number1, char operate, double number2){
    double result;
    switch (operate){
    case '+':
        result = number1 + number2;
        break;
    case '-':
        result = number1 - number2;
        break;
    case '*':
        result = number1 * number2;
        break;
    case '/':
        result = number1 / number2;
        break;
    default:
        result = -1;
        break;
    }
    return result;
}

int main(){

    std::cout << test(7.9 , '+' , 6.2 ) << "\n";
    std::cout << test(7.9 , '-' , 6.2 ) << "\n";
    std::cout << test(7.9 , '*' , 6.2 ) << "\n";
    std::cout << test(7.9 , '/' , 6.2 ) << "\n";
    std::cout << test(7.9 , '=' , 6.2 ) << "\n";


    return 0;
}
