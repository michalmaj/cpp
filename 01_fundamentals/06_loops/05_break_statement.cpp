/*
 * The break statement terminates the loop and transfers constrol to the very next statement
 * after the loop body.
*/

#include <iostream>

int main(){
    // For loop
    for(int items = 5; items > 0; --items){
        // Loop body
        std::cout << "Number of items: " << items << "\n";
        
        // Break from loop, when only two items left
        if (items == 2){
            std::cout << "Sorry 2 items are reserved.\n";
            break;
        }
        std::cout << "Buy an item\n";
    }
    std::cout << "Items are currently anavailable.\n";


    return 0;
}
