/*
 * Copy constructors
 * The copy constructor allows a class to create an object by copying an existing object. They except a
 * constant reference to another instance of the class as their argument.
 *
 * Move constructors
 * The move constructor allows the data of one object to be transferred completely to another object. They 
 * are more efficient alternative to the copy constructor since everything is being moved instead of copied.
 * They except a non-constant rvalue-reference to an instance of the class as their argument.
 *
 * Explict constructors
 * The explicit constructor is used to avoid implicit calls to class's constructor.
*/

#include <iostream>

class Account{
public:
    // All values of other can be copied into the new object. Both objects will have the same 
    // values afterward.
    Account(const Account& other);
    
    // After the move operation, other is in a moved-from state. Accessing it will result in undefinde 
    // behavior. To use it again, we would have to re-initialize it.
    Account(Account&& other);
    
    // Implicit constructors
    // Account(double b): balance(b){}
    Account(double b, std::string c): balance(b), cur(c){}
    
    // Explicit version
    explicit Account(double b): balance(b){}
    
    
private:
    double balance;
    std::string cur;
};

// Function
void strange(Account a){
    std::cout << "It works!\n";
}

int main(){
    // A double is being assigned to an Account object, but the compiler implicitly calls the constructor
    // that takes a double as an argument. Hence, the operation works wthout any errors.
    // If the constructor had beed made explicit, this statement would not have worked. For this, we 
    // would have to use explicit keyword.
    //Account acc1 = 100; // Error with explicit constructor
    Account acc2{100}; // Works
    Account acc3{100.0, "EUR"};
    
    //strange(100.0); // Error with explicit constructor
    strange(Account{100.0}); // Works
    
    
 
    return 0;
}
