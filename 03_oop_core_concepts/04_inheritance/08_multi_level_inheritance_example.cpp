/*
 * In case of multi-level inheritance, a derived class' members are looked up in the immediate parent class
 * and upwards until the ultimate base class until the member is found.
*/
#include <iostream>

/*
 * Class A defines two functions, init() and update(). Class B deriver from class A and defines its own
 * update() function. Class C is derived from class B and does not define any function.
*/
class A{
public:
    void init(){
        std::cout << "Class A initialized!" << std::endl;
    }
    void update(){
        std::cout << "Class A update!" << std::endl;
    }
};

class B: public A{
public:
    void update(){
        std::cout << "Class B updated!" << std::endl;
    }
};

class C: public B{};

int main(){
    C c;
    // The call to init() for an instance of C results in a lookup of a matching function C. 
    // Since that is not found, a matchin function is looked up in B.
    // SInce one is not found, a matching function is looked up in B. SInce one is not found, the lookup is
    // performed in A and a match is found.
    c.init();
    // Similarly, when update() is called, a matching function is not found in C, so it is looked up in B.
    // A match is found in B and the call resolves.
    c.update();
    
    // Note that this is all happening at compile time. The function calls init() and update() in main()
    // are bound to appropriate function definitions at compile time.

    return 0;
}
