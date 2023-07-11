/*
 * Function Template Argument Deduction by Value.
*/
#include <iostream>

template <typename T>
void funcValue(T param){
  std::cout << param << std::endl;
}

int main(){
  int x = 2023;
  const int cx = x;
  const int& rx = x;

  funcValue(x);
  funcValue(cx);
  funcValue(rx);


  return 0;
}
