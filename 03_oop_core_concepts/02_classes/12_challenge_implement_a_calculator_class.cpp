/*
 * Write a C++ class called Calculator with:
 * private member variables:
 *  num1 and mu2 (float type)
 * public member functions and constructors
 *  add(float n1, float n2), a function which returns the addition of two numbers
 *  subtract(float n1, float n2), a function which returns the subtraction of n1 from n2
 *  multiply(float n1, float n2), a function which returns the multiplication of numbers
 *  divide(float n1, float n2), a function which returns the division of n2 by n1
 *  Define a default constructor which initializes both numbers by zero.
*/
#include <iostream>

class calculator{
  // wrrite class member variables here
  float num1;
  float num2;
  
  public:
  calculator() {
    //write definition here
    num1 = 0;
    num2 = 0;
  }

  int add(float n1, float n2){
    //write definition here
    return n1 + n2;
  }

  float subtract(float n1, float n2){
    //write definition here
    return n2 - n1;
  }

  float multiply(float n1, float n2){
    //write definition here
    return n1 * n2;
  }

  float divide(float n1, float n2){
    //write definition here
    return n2 / n1;
  }
};

int main(){
    calculator obj;
    std::cout << "10 + 94 = " << obj.add(10, 94) << std::endl;
    std::cout << "94 - 10 = " << obj.subtract(10, 94) << std::endl;
    std::cout << "10 * 94 = " << obj.multiply(10, 94) << std::endl;
    std::cout << "94 / 10 = " << obj.divide(10, 94) << std::endl;    


    return 0;
}
