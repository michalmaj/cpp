/*
 * Problem Statement 
 * Write two sum functions which use the fold expressions to add all the values passed as arguments:
 *  - One function without an initial value.
 *  - One function with an initial value.
*/
#include <iostream>

// implement a function sum without an intital value here
template <typename ... Args>
auto sum(Args&& ... args){
  return ( ... + args);
}

// implement a function sum with an intital value here
template <typename T, typename ... Args>
auto sumWithStart(T&& t, Args&& ... args){
  return (t + ... + args);
}

int main(){
  // call your functions here
  std::cout << sum(1.1, 2.4, 3.8) << std::endl;
  std::cout << sumWithStart(20, 1, 2, 3) << std::endl;


  return 0;
}
