/*
 * A class tempalte defines a family of classes.
 *
 * Syntax:
 *  template <parameter-list>
 *  class-declaration
 * parameter-list: A non-empty comma-separated list of the template parameters, each of which is either a
 * non-type parameter, a type parameter, a template parameter, or a mixture of any of those.
 * class-declaration: A class declaration. The class name declared becomes a template name.
 *
 * Instantiation
 * The process of substituting the template parameters with the template arguments is called 
 * instantiation.
 * ------------------------------------------------------------------------------------------------------
 * Note: In contrast to a function template, a class template is not capable of automatically deriving 
 * the template parameters. Each template argument must be explicitly specified. This restriction no
 * longer exists in C++17.
 * ------------------------------------------------------------------------------------------------------
 *
 * Class Template Declaration
 *  template <typename T, int N>
 *  class Array{
 *    ...
 *  };
 *  Array<double, 10> doubleArray;
 *  Array<Accoubt, 1000> accountArray;
 *
 * Method Templates
 * Method templates are function templates used in a class or class template.
 * ----------------------------------------------------------------------------------------------------- 
 * Note: Method templates can be defined inside or outside the class. When we define the method template
 * outside the class, the synatx is quite complicated because we have to repeat the class template
 * declaration and the method template declaration.
 * ------------------------------------------------------------------------------------------------------
 * Example:
 *  template <class T, int N>
 *  class Array{
 *  public:
 *    template <class T2>
 *    Array<T, N>& operator = (const Array<T2, N>& a);
 *  };
 *  template <class T, int N>
 *  template <class T2>
 *  Array<T, N>& Array<T, N>::operator=(const Array<T2, N>& a){
 *    ...
 *  }
 * ----------------------------------------------------------------------------------------------------- 
 * Note: The destructor and copy constructor cannot be templates.
 * ------------------------------------------------------------------------------------------------------
 *
 * Inheritance
 * Class and class template can inherit from each other in arbitrary combinations.
 * If a class or a class template inherits from a class template, the methods of the base class or base
 * class template are NOT automaticall available in the derived class.
 * Example:
 *  template <typename T>
 *  struct Base{
 *    void func() {...}
 *  };
 *
 *  template <typename T>
 *  struct Derived: Base<T>{
 *    void func2(){
 *      func(); // Error
 *    }
 *  };
 * There are three ways to make a method from the derived class template available:
 *  1. Qualification via pointer: this->func().
 *  2. Introducing the name using Base<T>::func.
 *  3. Full qualified access Base<T>::func().
 *
 * Templates: Alias Templates
 * Alias templates, aka template typedef, allow us to give a name to partially bound templates. An 
 * example of partial specialization from templates is given below:
 *  template <typename T, int Line, int Col> 
 *  class Matrix{
 *    ...
 *  };
 *
 *  template <typename T, int Line>
 *  using Square = Matrix<T, Line, Line>;
 *
 *  template <typename T, int Line>
 *  using Vector = Matrix<T, Line, 1>
 *
 *  Matrix<int, 5, 3> ma;
 *  Square<double, 4> sq;
 *  Vector<char, 5> vec;
 */
#include <iostream>
#include <array>

class Account{
public:
  explicit Account(double amount=0.0): balance(amount) {}
  void deposit(double amount) {balance += amount;}
  void withdraw(double amount) {balance -= amount;}
  double getBalance() const {return balance;}

private:
  double balance;
};

template <typename T, int N>
class Array{
public:
  Array() = default;
  int getSize() const;

private:
  std::array<T, N> elem;
};

template <typename T, int N>
int Array<T, N>::getSize() const{
  return N;
}

int main(){
  Array<double, 10> doubleArray;
  std::cout << "doubleArray.getSize(): " << doubleArray.getSize() << std::endl;

  Array<Account, 1000> accountArray;
  std::cout << "accountArray.getSize(): " << accountArray.getSize() << std::endl;



  return 0;
}
