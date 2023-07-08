/*
 * Every template is parametrized by one or more template parameters, indicated in the parameter-list of
 * the template.
 * C++ supports three different kinds of templates parameters.
 *  1. Type parameter:
 *    std::vector<int> vec {1, 2, 3, 4, 5};
 *  2. Non-type parameter
 *    std::array<int, 5> arr{1, 2, 3, 4, 5};
 *  3. Template-template parameter
 *    template <typename T, template <typename, typename> class Cont>
 *    class Matrix{...};
 *
 *    Matrix<int, std::vector> myntVec;
 *
 * Types
 * A type parameter is a typical case for template arguments. Type parameters are class types and 
 * fundamental types.
 *
 * Non-Types
 * Non-types are template parameters which can be evaluated at compile time. The following types are 
 * possible:
 *  - Integers and enumerations.
 *  - Pointers to objects, functions, and attributes of a class.
 *  - References to objects and functions.
 *  - std::nullptr_t constant.
 * Note: Wth C++17, floating-point numbers and strings cannot be used as non-type parameters.
*/
#include <iostream>
#include <typeinfo>

class Account{
public:
  explicit Account(double amt): balance(amt) {}

private:
  double balance;
};

union WithString{
  std::string s;
  int i;
  WithString(): s("hello") {}
  ~WithString() {}
};

template <typename T>
class ClassTemplate{
public:
  ClassTemplate(){
    std::cout << "typeid(T).name(): " << typeid(T).name() << std::endl;
  }
};

int main(){
  ClassTemplate<int> clTempInt;
  ClassTemplate<double> clTempDouble;
  ClassTemplate<std::string> clTempString;

  ClassTemplate<Account> clTempAccount;
  ClassTemplate<WithString> clTempWithString;


  return 0;
}
