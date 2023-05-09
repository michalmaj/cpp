/*
 * std::unique_ptr has a specialization for array. The access is transparen, meaning that if the
 * std::unique_ptr manages the lifetime of an object, the operators for the object access are oveloaded
 * (operator* nad operator->). If std::unique_ptr manages the lifetime of an array, the index operator[]
 * is overloaded. The invocations of the operators are, therefore, transparently forwarded to the underlying
 * resource.
*/

#include <iostream>
#include <iomanip>
#include <memory>

class MyStruct{
public:
    MyStruct(){
        std::cout << std::setw(15) << std::left << this << " Hello" << std::endl;
    }
    ~MyStruct(){
        std::cout << std::setw(15) << std::left << this << " Goodbye" << std::endl;
    }
};

int main(){

    {
        std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[5]};
    }
    
    std::cout << std::endl;

  {
    std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[1]};
    MyStruct myStruct;
    myUniqueArray[0]=myStruct;
  }

  std::cout << std::endl;

  {
    std::unique_ptr<MyStruct[]> myUniqueArray{new MyStruct[1]};
    MyStruct myStruct;
    myStruct= myUniqueArray[0];
  }

  std::cout << std::endl;


    return 0;
}
