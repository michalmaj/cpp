/*
 * Function Template Argument Deduction by Unversal Reference.
*/
#include <iostream>

template <typename T>
void funcUnversal(T&& param){
  std::cout << param << std::endl;
}

int main(){
  int x = 2023;
  const int cx = x;
  const int& rx = x;

  funcUnversal(x);;
  funcUnversal(cx);;
  funcUnversal(rx);;
  funcUnversal(2023);;


  return 0;
}
