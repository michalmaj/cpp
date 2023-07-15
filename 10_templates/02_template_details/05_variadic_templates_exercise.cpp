/*
 * A typical example of a variadic template is the C function printf. Try to implement it with variadic 
 * templates.
*/
#include <iostream>

// This function is the boundary condition for the recursive calls.
void myPrintf(const char* format){
  std::cout << format;
}

// The myPrintf function uses variadic templates to implement a type-safe printf varian. The format 
// string is specified and thanks to function  template argument deduction, the copiler deduces the 
// type.
template <typename T, typename ... Args>
void myPrintf(const char* format, T value, Args ... args){
  // Loop is going as long as the format symbol is not equal to \0. When the format symbol is not equal 
  // to \0, two controls flows are possible. First, if the format starts with %, the first argument 
  // value is displayed, and myPrintf is invoked once more but with a new format symbol and an argument 
  // less. Second, if the format string does not start with %, the format symbol is just displayed.
  for(; *format != '\0'; ++format){
    if(*format == '%'){
      std::cout << value;
      myPrintf(format + 1, args ...);
      return;
    }
    std::cout << *format;
  }
}

int main(){
    myPrintf("% world% %\n","Hello",'!',2023);
}
