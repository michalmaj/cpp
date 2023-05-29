/*
 * Assignment operators
 * We can overload the assignment operator by implementing it as a copy or move assignment operator. It has
 * to be implemented in a class method. The implementation is very similar to a copy or move constructor.
 * If the assignment operator is not overloaded, the compiler creates one implicitly. This operator performs
 * a member-wise assignment of all the values from the object to be assigned. This is very similar to the 
 * behavior of the copy constructor, except that instead of a new object being created, the members of an
 * existing object are updated.
*/
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>

class Account{
public:
    Account() = default;
    Account(int n): numberOf(n), deposits(new double[n]) {}
    
    // In this example, the assignment operator for the Account class is overloaded for both copy and move
    // operations.
    Account(const Account& other): numberOf(other.numberOf), deposits(new double[other.numberOf]){
        std::copy(other.deposits, other.deposits + other.numberOf, deposits);
    }
    
    Account& operator=(const Account& other){
        if(this != &other){
            delete[] deposits;
            numberOf = other.numberOf;
            deposits = new double[other.numberOf];
            std::copy(other.deposits, other.deposits + other.numberOf, deposits);
        }
        return *this;
    }
    
    Account(Account&& other): numberOf(other.numberOf), deposits(other.deposits){
        other.deposits = nullptr;
        other.numberOf = 0;
    }
    
    Account& operator=(Account&& other){
        numberOf = other.numberOf;
        deposits = other.deposits;
        other.deposits = nullptr;
        other.numberOf = 0;
        return *this;
    }
    
    ~Account() noexcept{
        delete[] deposits;
    }
    
private:
    int numberOf;
    double* deposits;
};

int main(){
    std::cout << std::fixed << std::setprecision(10);
    
    Account account1(200'000'000);
    Account account2(100'000'000);
    
    auto start = std::chrono::system_clock::now();
    account1 = account2;
    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start;
    std::cout << "Account& operator=(const Account& other): " << dur.count() << " seconds" << std::endl;
    
    start = std::chrono::system_clock::now();
    account1 = std::move(account2);
    dur = std::chrono::system_clock::now() - start;
    std::cout << "Account& operator=(Account&& other): " << dur.count() << " seconds" << std::endl;

    return 0;
}
