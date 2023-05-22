/*
 * When we make an instance of the Derived class without parameters it will first call the default
 * constructor of the Base class and then the Derived class. In the same way, when we call the parametrized 
 * constructor of the Derived class, it will first call the parametrized constructor of the Base class and
 * then Derived class.
 *
 * When we make an instance of the Derived class it will first call the destructor of the Derived class and
 * then the Base class.
*/
#include <iostream>

// Base class
class Base{
public:
    Base(){
        std::cout << "Base class default constructor!\n"; 
    }
    Base(float i){
        std::cout << "Base class parametrized constructor!\n"; 
    } 
    ~Base(){
        std::cout << "Base class Destructor!\n";
    }   
};

// Derived class
class Derived: public Base{
public:
    Derived(){
        std::cout << "Derived class default constructor!\n"; 
    }
    Derived(float i): Base(i){
        std::cout << "Derived class parametrized constructor!\n"; 
    }  
    ~Derived(){
        std::cout << "Derived class Destructor!\n";
    }
    
};

int main(){
    Derived obj;
    std::cout << std::endl;
    Derived obj1(10.2);
    
    std::cout << std::endl;

    return 0;
}
