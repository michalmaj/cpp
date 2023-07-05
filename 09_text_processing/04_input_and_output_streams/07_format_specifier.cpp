/*
 * Format specifiers enable us to adjust the nput and output data explicitly.
 * We can use manipulators as format specifiers. The format specifiers are available as manipulators and
 * flags.
*/
#include <iostream>

int main(){
  int num{2023};

  std::cout << "dec: " << num << "\n\n";

  std::cout.setf(std::ios::hex, std::ios::basefield);
  std::cout << "hex: " << num << "\n\n";
  std::cout.setf(std::ios::dec, std::ios::basefield);
  std::cout << "dec: " << num << "\n\n";

  std::cout << std::hex << "hex: " << num << std::endl;
  std::cout << std::dec << "dec: " << num << std::endl;

  return 0;
}
