/*
 * Implement four different class templates which accept an integral, a pointer, a reference, or a nullptr
 * as a non-type parameter. You need to display the type of data passed as a parameter.
*/

#include <iostream>
#include <cstddef>
#include <typeinfo>

// Write class templates for given commented code
template <char c>
class AcceptChar{
public:
  AcceptChar(){
    std::cout << "AcceptChar: " << typeid(c).name() << std::endl;
  }
};

template <int(*func)(int)>
class AcceptFunction{
public:
  AcceptFunction(){
    std::cout << "AcceptFunction: " << typeid(func).name() << std::endl;
  }
};

template <int(&arr)[5]>
class AcceptReference{
public:
  AcceptReference(){
    std::cout << "AcceptReference: " << typeid(arr).name() << std::endl;
  }
};

template <std::nullptr_t N>
class AcceptNullptr{
public:
  AcceptNullptr(){
    std::cout << "AcceptNullptr: " << typeid(N).name() << std::endl;
  }
};

int myFunc(int){return 2023;}
int arr[5];

int main() {
  // uncomment these lines after implementing codes

  
  AcceptChar<'c'> acceptChar;
  AcceptFunction< myFunc> acceptFunction;
  AcceptReference< arr > acceptReference;
  AcceptNullptr< nullptr > acceptNullptr;
}
