/*
 * Template can be implicitly and explicitly instantiated. Implicit instantiation means automatically 
 * and explicit means manually.
 *
 * Implicit:
 *  std::vector<int> vec{};
 *  bool isSmaller<double>(fir, sec);
 *  bool isSmaller(fir, sec);
 *
 * Explicit:
 *  template class std::vector<int>;
 *  template bool std::vector<double>::empty() const;
 *  template bool isSmaller<double>(double, double);
 *  template bool isSmaller(double, double);
 *
 * Lazy evaluation:
 * When a class is instantiated, only the method declarations are available. The definition of a method 
 * is only instantiated when it is used.
 * It is not necessary that all methods of class templates are valid for the template arguments. We can
 * only use the methods, which are valid for a given instantiation.
 *
 * Example:
 * In the below example, we wll implement a template class Array which includes a function getSize() that
 * returns the size of the element N passed int the constructor. We will also define a template function
 * isSmaller bool and its return type is declared explicitly which returns true if the first passed
 * argument is less than the second one.
*/
#include <iostream>
#include <vector>

template <typename T, int N>
class Array{
public:
  Array() = default;

  int getSize() const {return N;}

  std::vector<T> elem;
};

template <typename T>
bool isSmaller(T fir, T sec){
  return fir < sec;
}

template class std::vector<int>;
template bool std::vector<double>::empty() const;

template class Array<int, 20>;
template int Array<double, 5>::getSize() const;

template bool isSmaller(double, double);
template bool isSmaller<int>(int, int);

int main(){
  std::cout << std::boolalpha << "implicit" << std::endl;
  
  std::cout << std::endl;
  
  std::vector<int> vec{};
  std::cout << "vec.size(): " << vec.size() << std::endl;
  
  Array<int, 10> arr;
  std::cout << "arr.getSize(): " << arr.getSize() << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "isSmaller(5, 10): " << isSmaller(5,10) << std::endl;
  
  std::cout << "isSmaller<double>(5.5, 6.5): " << isSmaller<double>(5.5, 6.5) << std::endl;


  return 0;
}
