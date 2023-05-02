/*
 * The while loop keeps executing a particular code block until the given condition is true. It
 * does not know in advance how many times the loop body should be executed.
 * The condition in the whle loop is evaluated before execution the statements inside its body.
 * Therefore, the while loop is called an entry-controlled loop.
*/

#include <iostream>

int main(){
    // Initialize the varable called money
    int money = 20;
    
    // Initialize varaible price
    int price = 5;
    
    // Prints value of variables
    std::cout << "Initial money: " << money << "\n";
    std::cout << "Price f the item: " << price << "\n";
    
    // Perform loop until we have enough money
    while(money >= price){
        // Body of the while loop
        std::cout << "Buy an item\n";
        // Decrease the amount of our money by price of the item
        money -= price;
        std::cout << "Remaining money: " << money << "\n";
    }
    std::cout << "You don't hve enough money to buy another item" << "\n";



    return 0;
}
