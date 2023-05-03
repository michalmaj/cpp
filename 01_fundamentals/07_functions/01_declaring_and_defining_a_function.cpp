/*
 * In C++, function creation consists of the following two steps:
 *  1. Function declaration.
 *  2. Function definition.
 *
 * The function declaration informs the compiler about:
 *  1. The return type of function.
 *  2. The function name.
 *  3. The number of parameters.
 *
 * Tha basic syntax for declaring a function in C++ is:
 *  return_type function_name (function_parameters);
 *
 * Return type specifies what type of data a function returns in output to the calling point
 * after performing its task.
 * It is possible for a function to return nothing in output. Such function have a void return
 * type.
 *
 * Whenever we declare a functon, we give it a unique name. We then use the same name to call it
 * throughout the program.
 *
 * When we call a function, we pass values to the function parameters. These values are known as
 * arguments or actual parameters.
 *
 * A function's definition tells what a function will do when it is called.
 * In the below code, we declare a function before the main function. Then, we define it after
 * the main function.In C++, statements are executed from top to bottom. If we don't declare the
 * function before main(), our program will be unware of it and we will get a compiler error.
 * Note: we can declare and define function in one shot.
 *
 * The functions created in a program are not executed until we call them. When we call
 * function, control is given to the very first statement inside the called function.
 * To call a function in a program, we have to write a function name, followed by values of
 * arguments in the round brackets and the semicolon.
 * Note: We can call a function from any other function in a program.
*/

#include <iostream>

// Function declaration
// Note: It is not necessary to give parameters names in the function declaration. You may only
// declare their data type. In ths case in parentheses we would have only (int, int)
int make_juice(int water_glass, int fruit);


int main(){
    // Declare and initialize variables apple and water
    int apples = 5;
    int water_glass = 3;
    
    // Declare a variable for storing a make_juce function
    int apple_juice;
    
    // Call function make_juice and save its output in apple_juice variable
    apple_juice = make_juice(water_glass, apples);
    
    // Print value of apple_juice
    std::cout << "Number of apple juice: " << apple_juice << "\n"; 
    
    // We can call function as many times as we want
    // Note: We can initialize a variable and then pass the identifier to the function, or we
    // can pass the value directly to the function parameters.
    int orange_juice = make_juice(2, 5);
    
    // Print value of orange_juice
    std::cout << "Number of orange juice: " << orange_juice << "\n"; 



    return 0;
}

// Function defintion.
int make_juice(int water_glass, int fruit){
    // Define new variable.
    // Note: Ths variable will be only visible in ths scope, between curlry braces {}
    int juice;
    
    // Add water and fruit and save output in juice
    juice = water_glass + fruit;
    
    // Return juice value in output
    return juice;
}
