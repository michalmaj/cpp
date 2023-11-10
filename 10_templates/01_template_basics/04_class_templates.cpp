/*
 * A class template defines a family of classes
 *
 * Syntax
 *  template <parameter-list>
 *  class-declaration
 * parameter-list: A non-empty comma-separated list of the template parameters, each of which os either a non-type
 * parameter, a type parameter, a template parameter, or a mixture of those.
 * class-declaration: A class declaration. The class name declared becomes a template name.
 *
 * Instantiation
 * The process of substituting the template parameters with template arguments is called instantiation.
 * In contrast to a function template, a class template is not capable of automatically deriving the template
 * parameters. Each template argument must be explicitly specified. This restriction no longer exists with C++17.
 * Function Template Declaration
 *  template <typename T>
 *  void xchg(T& x, T& y){...
 *  int a, b;
 *  xchg(a, b);
 * Class Template Declaration
 *  template <typename T, int N>
 *  class Array{...
 *  Array<double, 10> double Array;
 *  Array<Account, 1000> accountArray;
 *
 * Method Templates
 * Method templates are function templates used in a class or class template.
 * Method templates can be defined inside or outside the class. When we define the method template outside the class,
 * the syntax is quite complicated because we have to repeat the class template declaration and the method template.
 *  template <class T, int N> class Array{
 *  public:
 *      template <class T2>
 *      Array<T, N>& operator=(const Array<T2, N>& a);...
 *  };
 *
 *  template <class T, int N>
 *  template <class T2>
 *  Array<T, N>& Array<T, N>::operator=(const Array<T2, N>& a{...
 * Note: The destructor and constructor cannot be templates.
 *
 * Inheritance
 * Class and class template can inherit from each other is arbitrary combinations.
 * If a class or a class template inherits from a class template, the methods of the base class or base class template
 * are not automatically available in the derived class.
 *  template <typename T>
 *  struct Base{
 *      void func() {...
 *  };
 *  template <typename T> struct Derived: Base<T>{
 *      void func2() {
 *      func(); //Error
 *      }
 *  };
 * There are three ways to make a method from the derived class template available:
 *  1. Qualification via this pointer: this->func()
 *  2. Introducing the name using Base<T>::func
 *  3. Full qualified access Base<T>::func()
 *
 * Templates: Alias Templates
 * Alias templates, aka templates typedefs, allow us to give a name to partially bound templates. An example of partial
 * specialization templates:
 *  template <typename T, int Line, int Col> class Matrix{...
 *
 *  template <typename T, int Line>
 *  using Square = Matrix<T, Line, Line>
 *
 *  template <typename T, int Line>
 *  using Vector = Matrix<T, Line, 1>;
 *
 *  Matrix<int, 5, 3> ma;
 *  Square<double, 4> sq;
 *  Vector<char, 5> vec;
 */
// Template in Class
#include <iostream>

class Account{
public:
    explicit Account(double amount=0.0): balance(amount){}

    void deposit(double amount){
        balance += amount;
    }

    void withdraw(double amount){
        balance -= amount;
    }

    [[nodiscard]]double getBalance() const{
        return balance;
    }

private:
    double balance;
};

template <typename T, int N>
class Array{
public:
    Array() = default;
    [[nodiscard]]int getSize() const;
private:
    T elem[N];
};

template <typename T, int N>
int Array<T, N>::getSize() const {
    return N;
}

int main(){
    std::cout << std::endl;

    Array<double, 10> doubleArray;
    std::cout << "doubleArray.getSize(): " << doubleArray.getSize() << std::endl;

    Array<Account, 1000> accountArray;
    std::cout << "accountArray.getSize(): " << accountArray.getSize() << std::endl;

    return 0;
}