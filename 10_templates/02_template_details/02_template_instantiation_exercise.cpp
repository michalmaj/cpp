/*
 * Problem Statement
 * Define a class template with at least one method. This method should not be valid for all possible 
 * template arguments. Instantiate the class template for an invalid template argument. What happens, 
 * when you:
 *  - don’t instantiate?
 *  - implicitly instantiate?
 *  - or explicitly instantiate the method?


*/
#include <iostream>
#include <vector>

// Define a class template here with one method
template <int Nom, int Denom>
class Rational{
public:
  int getFloor(){
    return Nom / Denom;
  }
};

//template int Rational<5, 0>::getFloor();

int main() {
  // call these methods here
  Rational<5, 3> rat1;
  std::cout << "rat1.getFloor(): " << rat1.getFloor() << std::endl;

  Rational<5, 0> rat2;
  //std::cout << "rat2.getFloor(): " << rat2.getFloor() << std::endl;


  return 0;
}
