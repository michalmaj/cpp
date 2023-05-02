/*
 * A loop inside the body of another loop is called a nested loop.
*/

#include <iostream>

int main(){

    // Create a mutilication table from 1 to 10
    for (int i = 1; i <= 10; ++i){
        for (int j = 1; j <= 10; ++j)
            std::cout << i << " * " << j << " = " << i * j << "\t";
        std::cout << "\n";
    }


    return 0;
}
