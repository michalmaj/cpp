/*
 * In this challenge, you will be given the names, account numbers, and balances of a customers. Your task
  * is to return the account numbers of customers with a balance of less than $500.
*/

#include <iostream>

// Structure to store Account information
struct Account {
    std::string name;
    int number;
    double balance;
};

// Function to find account numbers with less than 500 balance
void check_account(struct Account p[], int arr[], int size) {
    // Traverse array
    for(int i{0}; i < size; ++i){
        // Check if balance less than 500
        if(p[i].balance < 500)
            arr[i] = p[i].number;
        else
            arr[i] = -1;
    }
}

int main(){
    Account p[]{{"John",578328,890.000000 },{"Alex",908210,430.200000},{"Kim",165216,98.500000}};
    int arr[]{0,0,0};

    check_account(p, arr,3);
    for(int i{0}; i < 3; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}
