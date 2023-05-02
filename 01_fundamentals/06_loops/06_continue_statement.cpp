/*
 * The continue statement makes the compiler skip the current iteration and move to the next one
*/

#include <iostream>

int main(){
    // for loop
    for (int items = 5; items > 0; --items){
        std::cout << "We have " << items << " items left\n";
        if (items == 2){
            std::cout << "Sorry! Item #" << items << " is reserved\n";
            std::cout << "You can't buy it\n";
            continue;
        }
        std::cout << "Buy an item\n";
    }
    std::cout << "All items are sold out\n";


    return 0;
}
