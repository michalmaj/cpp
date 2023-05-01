/*
 * The switch statement evaluates the given expression and then compares its value with each
 * case label. If the value of a case label equals the value of the expression, the statement(s) 
 * specific to that case is executed.
 *
 * Switch expression and case label accept variables of int or char data types.
 *
 * If we don't add a break statement to a case, the code specfic to all the proceeding cases
 * is also executed.
 * The default case is optional in the switch statement. It can be used anywhere in the switch
 * statement.
*/

#include <iostream>

int main(){
    // Initialize variable grade
    char grade = 'C';

    // switch statement
    switch (grade){
    case 'A':
        std::cout << "Exceptional performance!\n";
        break;
    case 'B':
        std::cout << "Well done!\n";
        break;
    case 'C':
        std::cout << "Good!\n";
        break;
    case 'D':
        std::cout << "You need more hardwork!\n";
        break;
    case 'E':
        std::cout << "Almost failed!\n";
        break;
    case 'F':
        std::cout << "Fal!\n";
        break;
    default:
        std::cout << "Invalid input\n";
        break;
    }


    return 0;
}
