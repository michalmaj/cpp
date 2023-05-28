/*
 * In this challenge, we'll implement an account class along with two derived classes saving and current.
 * Problem statement:
 * A parent class named Account.
 *  Inside it define
 *      a protected float member balance
 *  We have three virtual functions:
 *      void Withdraw(float amount);
 *      void Deposit(float amount);
 *      void printBalance();
 * Then, there are two derived classes.
 *  Savings class
 *      has a private member interest_rate set to 0.8
 *      Withdraw(float amount) deducts amount from balance with interest_rate
 *      Deposit(float amount) add amount in balance with interest_rate
 *      printBalance() displays the balance in the account.
 *  Current class
 *      Withdraw(float amount) deducts amount from balance
 *      Deposit(float amount) add amount in balance with interest_rate
 *      printBalance() displays the balance in the account.
 *
 * In addition create an std::vector of references of Savings and Current objects
*/
#include <iostream>
#include <vector>
#include <functional>

class Account{
protected:
    float balance;

public:
    Account(float b): balance(b) {}  
    virtual void Withdraw(float amount) = 0;
    virtual void Deposit(float amount) = 0;
    virtual void printBalance() = 0; 
};

class Savings: public Account{
private:
    float interest_rate = 0.8;
    
public: 
    Savings(float b): Account(b) {}

    void Deposit(float amount){
        balance += amount + (amount * interest_rate);
    }
    
    void Withdraw(float amount){
        balance -= amount + (amount * interest_rate);
    }
    
    void printBalance(){
        std::cout << "Balance in your saving account: " << balance << std::endl;
    }
};

class Current: public Account{
public:
    Current(float b): Account(b) {}
    
    void Deposit(float amount){
        balance += amount;
    }

    void Withdraw(float amount){
        balance -= amount;
    }

    void printBalance(){
        std::cout << "Balance in your saving account: " << balance << std::endl;
    }
};

int main(){
    Savings s1(50000);
    Current c1(50000);
    std::vector<std::reference_wrapper<Account>> acc{s1, c1};
    acc.at(0).get().Deposit(1000);
    acc.at(0).get().printBalance();
    acc.at(0).get().Withdraw(3000);
    acc.at(0).get().printBalance();  

    std::cout << std::endl;
    
    acc.at(1).get().Deposit(1000);
    acc.at(1).get().printBalance();
    acc.at(1).get().Withdraw(3000);
    acc.at(1).get().printBalance();


    return 0;
}
