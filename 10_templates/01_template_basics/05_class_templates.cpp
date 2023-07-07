/*
 * Inheritance in Class Templates.
*/
#include <iostream>

template <typename T>
class Base{
public:
  void func1() const {
    std::cout << "func1()" << std::endl;
  }

  void func2() const {
    std::cout << "func2()" << std::endl;
  }

  void func3() const {
    std::cout << "func3()" << std::endl;
  }
};

template <typename T>
class Derived: public Base<T>{
public:
  // Second solution: Introducing the name using Base<T>::func
  using Base<T>::func2;   

  void callAllBaseFunctions(){
    // First solution: Qualification via this pointer: this->func()
    this->func1();
    
    // Senocd solution: call
    func2();
    
    // Full qualified access Base<T>::func()
    Base<T>::func3();
  }
};

int main(){
  Derived<int> derived;
  derived.callAllBaseFunctions();
  std::cout << std::endl;

  return 0;
}
