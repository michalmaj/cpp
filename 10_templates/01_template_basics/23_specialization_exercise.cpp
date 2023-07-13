/*
 * Problem Statement
 * The class template Type in the code below returns to each type the name unknown.
 *  - Use the class template Type as a starting point to write a type introspection system with the help 
 *    of partial and full specialization.
 *  - You need to write code for int, double, an arbitrary class named Account, pointer, const, and 
 *    string.
*/
// In code below, we will separately define the partial and full specialization of the class template
// Type. Tha partial and full specialization accept an int, double, Account, std::string, const and 
// pointer. On calling each type, the relative type is returned. We won't define the full specialization
// for float, so when instantiating the class tamplate for float, it gives an unknown in response.
#include <iostream>
#include <string>

// Implement with full and partial specialization
// Write your code here
class Account{};

template<typename T>
struct Type{
  std::string getName() const {
    return "unknown";
  }
};

template <typename T>
struct Type<T*>{
  std::string getName() const {
    return "pointer";
  }
};

template <typename T>
struct Type<const T>{
  std::string getName() const {
    return "const";
  }
};

template <>
struct Type<int>{
  std::string getName() const {
    return "int";
  }
};

template <>
struct Type<double>{
  std::string getName() const {
    return "double";
  }
};

template <>
struct Type<std::string>{
  std::string getName() const {
    return "std::string";
  }
};

template <>
struct Type<Account>{
  std::string getName() const {
    return "Account";
  }
};

int main(){

  std::cout << std::boolalpha << std::endl;

  // call objects for each defined templetes here

  // An example of float is given below which returns "unknown"
  Type<float> tFloat;
  std::cout << "tFloat.getName(): " << tFloat.getName() << std::endl;

  Type<const float> tConstFloat;
  std::cout << "tConstFloat.getName(): " << tConstFloat.getName() << std::endl;
   
  Type<float*> tFloatPointer;
  std::cout << "tFloatPointer.getName(): " << tFloatPointer.getName() << std::endl;
   
  Type<double> tDouble;
  std::cout << "tDouble.getName(): " << tDouble.getName() << std::endl;

  Type<std::string> tString;
  std::cout << "tString.getName(): " << tString.getName() << std::endl;

  Type<int> tInt;
  std::cout << "tInt.getName(): " << tInt.getName() << std::endl;

  Type<Account> tAccount;
  std::cout << "tAccount.getName(): " << tAccount.getName() << std::endl;

  std::cout << std::endl;

}
