/*
 * Adjust the following program so that all implicit conversion are possible.
 #include <iostream>

class A{};

class B{};

class MyClass{
  public:
    MyClass(){}
    explicit MyClass(A){}                // since C++98
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

  // explicit invocation
  MyClass myClass1(a);
  // implicit conversion from A to MyClass
  MyClass myClass2=a;
  needMyClass(a);

  // MyClass -> B
  MyClass myCl;

  // explicit invocation
  B b1(myCl);
  // implicit conversion from MyClass to B
  B b2= myCl;
  needB(myCl);

  // MyBool -> bool conversion
  MyBool myBool;
  if (myBool){};
  int myNumber = (myBool)? 1998: 2011;
  // implict conversion
  int myNewNumber = myBool + myNumber;
  auto myTen = (20*myBool -10*myBool)/myBool;

  std::cout << myTen << std::endl;

}
*/

// Solution:
// Recall that the explicit keyword s solely responsible for preventing implicit conversion.
// Hence, the trick is to simply remove explicit from the conversion constructor and operator. This will
// enable implicit conversion again.
#include <iostream>

class A{};

class B{};

class MyClass{
  public:
    MyClass(){}
    MyClass(A){}                // since C++98
    operator B(){return B();}   // new with C++11
};

void needMyClass(MyClass){};
void needB(B){};

struct MyBool{
  operator bool(){return true;}
};

int main(){

  // A -> MyClass
  A a;

  // explicit invocation
  MyClass myClass1(a);
  // implicit conversion from A to MyClass
  MyClass myClass2=a;
  needMyClass(a);

  // MyClass -> B
  MyClass myCl;

  // explicit invocation
  B b1(myCl);
  // implicit conversion from MyClass to B
  B b2= myCl;
  needB(myCl);

  // MyBool -> bool conversion
  MyBool myBool;
  if (myBool){};
  int myNumber = (myBool)? 1998: 2011;
  // implict conversion
  int myNewNumber = myBool + myNumber;
  auto myTen = (20*myBool -10*myBool)/myBool;

  std::cout << myTen << std::endl;

}
