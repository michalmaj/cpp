// Inheritance in Class Templates
#include <iostream>

template <typename T>
class Base{
public:
    void func1() const{
        std::cout << "func1()" << std::endl;
    }
    void func2() const{
        std::cout << "func2()" << std::endl;
    }
    void func3() const{
        std::cout << "func3()" << std::endl;
    }
};

// Derived class is publicly inherited from Base and may, therefore, use in its method call AllBaseFunctions.
template <typename T>
class Derived: public Base<T>{
public:
    using Base<T>::func2; // Introduce the name into current scope.

    void callAllBaseFunctions(){
        this->func1(); // Make the name dependent
        func2();
        Base<T>::func3(); // Call the name fully qualified. It can break a virtual dispatch.
    }
};

int main(){
    std::cout << std::endl;

    Derived<int> derived;
    derived.callAllBaseFunctions();


    return 0;
}