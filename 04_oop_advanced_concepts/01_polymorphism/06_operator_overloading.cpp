/*
 * C++ alows us to defince the behavior of operators for our own data types. This is known as operaotr
 * overloading.
 * Operators vary in nature and therefore, require different operands. The number of operands for a
 * particular operator depends on:
 *  1. The knd of operator (infix, prefix, etc.).
 *  2. Whether the operator is a method or function.
 *
 * Rules:
 * 1. We cannot change the precedence of an operator. The compiler omputes all operators in order of
 *    precedence. We cannot alter this order. Hence, whatever operation our operator performs, it will be
 *    computed after the operator with higher precedence.
 * 2. Derived classes inhrit all the operators of their base classes except the assignemnt operator. Each
 *    class needs to overload the = operator.
 * 3. All operators other then the function call operator cannot have default arguments.
 * 4. Operators can be called explicitly. A benefit of overloading an operator is that it can be used 
 *    directly with its operands. However, the compiler may cause some implicit conversion in this process.
 *    We can make explicit calls to the overloaded operator in the following format: a.operator += (b).
 * 
 * Prohibited operators
 * The following operators cannot be overloaded:
 *  - .
 *  - ::
 *  - ?:
 *  - sizeof
 *  - .*
 *  - typeof
*/
#include <iostream>

class Account{
public:
    explicit Account(double b): balance(b) {}
    
    // The += operator is being overloaded for the Account class. Now, we can add and assign a 
    // double to an Account object without any problems. However, this will not support Account += Account,
    // where both operands are of the Account type.
    Account& operator+=(double b){
        balance += b;
        return *this;
    }
    
    // This friends function supports the additional assignment between two Account objects. The friend
    // function can access the private member, balance. Hence, we can perform a.balance + b.balance.
    friend Account& operator+=(Account& a, Account& b);
    
    // The << output operator has also been overloaded in a friend function. Now, std::cout << acc; will
    // print the balance of the acc object.
    friend std::ostream& operator<<(std::ostream& os, const Account& a);
private:
    double balance;
};

Account& operator+=(Account& a, Account& b){
    a.balance += b.balance;
    return a;
}
std::ostream& operator<<(std::ostream& os, const Account& a){
    os << a.balance;
    return os;
}

int main(){
    Account acc1(100.0);
    Account acc2(100.0);
    Account acc3(100.0);
    
    acc1 += 50.0;
    acc1 += acc1;
    
    acc2 += 50.0;
    acc2 += acc2;
    
    acc3.operator+=(50.0);
    
    std::cout << "acc1: " << acc1 << std::endl;
    std::cout << "acc22: " << acc2 << std::endl;
    

    return 0;
}
