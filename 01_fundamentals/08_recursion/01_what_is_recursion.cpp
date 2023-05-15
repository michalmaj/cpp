/*
 * A function that calls itself repeatedly until some condition is met is known as a recursive function.
 * The process whereby a function repeatedly calls itself until a condition is met is known as recursion.
 *
 * Example:
 * Suppose you are standing in a line to buy a movie ticket. You want to komw the price of the ticket, but
 * only the first person in line knows the price.
 * You can apprach the first person and ask him the price directly. However, if you leave the line, someone
 * else wll take your place. Therefore, you will have to use the following approach:
 *  1. You will ask for the ticket price from the person in fron of you.
 *  2. That person doesn't want to leave the line either. Therefore, they will ask the same question from
 *     the person in front of them. This process will continue until the price is asked from the first
 *     person in the line.
 *  3. The first person in line will tell the ticket price. After that, each person in line will know the
 *     ticket price through the person standing in fron of them.
*/
#include <iostream>

int ticket_price(int person){
    int price;
    if(person == 1){
        price = 100;
        return price;
    }
    else
        person--;
    
    std::cout << "Process is continue - person in queue: " << person << std::endl;
    
    return ticket_price(person);
}

int main(){

    int price = ticket_price(5);
    std::cout << "Ticket price: " << price << std::endl;

    return 0;
}
