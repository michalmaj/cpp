/*
 * Since we have divided the larger subproblem into a series of smaller subproblems of itself, after some
 * time the problem will become so simple that we can solve it directly without dividing it any further.
 * This is a base case.
 * The condition where the function stops calling itself in its body s known as the base case.
 * The recursive function only knows how to solve the simplest case known as base case. When we call the
 * recursive function with a base case, it simply returns us the result.
 * Note: Every recursive function must have a base case or an error is generated because of memory overflow.
*/
#include <iostream>

int ticket_price(int person){
    int price;
    if(person == 1){
        price = 100;
        return price;
    }
    else{
        std::cout << "Person " << person << " is asking price\n";
        person--;
        price = ticket_price(person);
        std::cout << "Person " << person << " is telling price\n";
        return price;
    }
}

int main(){
    int price = ticket_price(5);
    std::cout << "Ticket price: " << price << "\n";


    return 0;
}
