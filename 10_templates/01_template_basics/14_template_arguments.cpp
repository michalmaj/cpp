/*
 * Function Template Argument Deduction by Reference
*/
#include <iostream>

template <typename T>
void func(T& param) {
  std::cout << "Inside func: " << param << std::endl;
}

template <typename T>
void constFunc(const T& param) {
  std::cout << "Inside const func: " << param << std::endl;
}

int main(){
  int x = 2023;
  const int cx = x;
  const int& rx = x;

  func(x);
  func(cx);
  func(rx);

  constFunc(x);
  constFunc(cx);
  constFunc(rx);

  return 0;
}
