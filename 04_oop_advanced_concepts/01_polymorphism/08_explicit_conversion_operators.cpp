/*
 * In C++98, the explicit keyword wan only supported for conversion constructors. Conversion operators
 * converted user-defined objects implicitly.
 * All this changed in C++11. Now, we can overload conversion opertors to explicitly prevent and permit 
 * conversions.
 * Example:
 * explicit MyClass(A) {} // Converting constructor - C++98
 * explicit operator B() {} // Converting operator - C++11 
 * As we can see, the explicit keyword can now be used when overloading the conversion operator, B().
*/
#include <iostream>

class A{};

class B{};

class MyClass{
  public:
    MyClass(){}
    // We have defined an explicit conversion constructor from A to MyClass.
    explicit MyClass(A){}                // since C++98
    // We have defined an explicit conversion operator from MyClass to B.
    explicit operator B(){return B();}   // new with C++11
};

void needMyClass(MyClass){};
void needB(B){};

struct MyBool{
  explicit operator bool(){return true;}
};

int main(){

  // A -> MyClass
  A a;

  // Explicit invocation
  // The constructor call works fine
  MyClass myClass1(a);
  
  // Implicit conversion from A to MyClass
  // In this case we cannot do the implicit conversion - CE
//  MyClass myClass2=a;
  // Will not be able to implicit convert object a to MyClass. This functionality has been available
  // since C++98
//  needMyClass(a);

  // MyClass -> B
  MyClass myCl;

  // Explicit invocation
  B b1(myCl);
  
  // Implicit conversion from MyClass to B
  // Use an implicit conversion. Due to the explicit conversion operator B - line below is not valid
//  B b2= myCl;
//  needB(myCl);

  // MyBool -> bool conversion
  MyBool myBool;
  if (myBool){};
  int myNumber = (myBool)? 1998: 2011;
  
  // Implicit conversion - also won't work
//  int myNewNumber = myBool + myNumber;
//  auto myTen = (20*myBool -10*myBool)/myBool;

//  std::cout << myTen << std::endl;

}
