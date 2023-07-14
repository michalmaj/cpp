/*
 * Template Perfect Forwarding
 * In the below examplem we will create a createT function which invokes the constructor T with the 
 * arguments args. If there is no value passed, t invokes the default constructor. The magic of the 
 * factory function createT is that it can invoke each constructor. Thanks to perfect forwading, each 
 * value can be used such as an lvalue or an rvaluel thanks to parameter packs, any number of arguments
 * can be used. In the case of MyStruct, a constructor that requires three arguments is used.
 * The pattern of the function template createT is exactly the pattern, factory function such as 
 * std::make_unique, std::make_shared, std::make_pair, std::make_tuple use.
*/
#include <iostream>
#include <utility>

template <typename T, typename ... Args>
T createT(Args&& ... args){
  return T(std::forward<Args>(args) ...);
}

struct MyStruct{
  MyStruct(int&, double&, double&&){}
  friend std::ostream& operator<<(std::ostream& out, const MyStruct&){
    out << "MyStruct\n";
    return out;
  }
};

int main(){
  double myDouble = createT<double>();
  std::cout << "myDouble: " << myDouble << std::endl;

  int myInt = createT<int>(1);
  std::cout << "myInt: " << myInt << std::endl;


  std::string myString = createT<std::string>("My String");
  std::cout << "myString: " << myString << std::endl;

  MyStruct myStruct = createT<MyStruct>(myInt, myDouble, 3.14);
  std::cout << "myStruct: " << myStruct << std::endl;


  return 0;
}
