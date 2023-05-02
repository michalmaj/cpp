/*
 * The do-while loop is similar to the while loop, with the exception that it executes the block
 * of code and then checks the given condition. Because of this, it is called an exit-controlled
 * loop.
 * Like the while loop, the do-while loop does not know in advance how many times the loop body
 * should be executed.
*/

#include <iostream>

int main(){
    // Initialize the variable money
    int money = 0;
    
    // Initialize the variable price
    int price = 5;
    
    // Print value of variables
    std::cout << "Initial money: " << money << "\n";
    std::cout << "Item price: " << price << "\n";
    
    // do-while loop
    do { // Body will be executed at least once!
        // Body of do-while loop
        std::cout << "Buy an item\n";
        money -= price;
        std::cout << "Remaining money: " << money << "\n";
    }while (money >= price);
    std::cout << "Not enought money to buy another item\n";


    return 0;
}
