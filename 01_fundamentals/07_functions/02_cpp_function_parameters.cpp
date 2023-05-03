/*
 * We can declare the variables inside the fuction definition as parameters. We specify the list
 * of parameters separated by a comma inside the round brackets. In C++, we have:
 *  - Formal parameters.
 *  - Actual parameters.
 *
 * Formal parameters are the variables definde in the function definition. These variables
 * receive values from the calling function. Formal parameters are commonly known as parameters.
 *
 * Actual parameters are the variables or values passed to the function when it is called.
 * These variables supply value to the called function. Actual parameters are commonly known
 * as arguments.
 *
 * Default parameter values. If we provided fewer or no arguments to the calling function, the
 * default values of the parameters are used. We specify the default values in the functon
 * declaration using equal sign =.
*/

#include <iostream>

// Define function with default parameters
int make_juice(int water=1, int fruit=3){
    int juice = water + fruit;
    return juice;
}

int main(){
    int apple_juice = make_juice();
    std::cout << "Apple juice: " << apple_juice << "\n";
    
    int orange_juice = make_juice(2, 3);
    std::cout << "Orange juice: " << orange_juice << "\n";

    return 0;
}
