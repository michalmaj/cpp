/*
 * The for loop keeps executing a paricular code block as long as given condition is true.
*/

#include <iostream>

int main(){
   
    // for loop
    // Variable numberOfItems exists only inside body of this loop!
    for (int numberOfItems = 5; numberOfItems > 0; --numberOfItems) {
        // Loop body
        std::cout << "Number of items: " << numberOfItems << "\n";
        std::cout << "Buy an item\n";
    }


    return 0;
}
