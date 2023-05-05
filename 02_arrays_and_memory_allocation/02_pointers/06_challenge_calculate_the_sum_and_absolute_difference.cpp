/*
 * Your task is to write a function sum_difference. In the function parameter, you will pass the two
 * pointers of type int, and the function will return nothing in the output.
 * void sum_difference(int* value1, int* value2);
 * Your function should:
 * Task 1: Sum the values pointed by value1 and value2 and store the result in the location pointed by
 * value1.
 * Task 2: Calculate the absolute difference of the value pointed out by value1 and value2. Store the
 * result in the location pointed by value2.
*/

#include <iostream>

void sum_difference(int* value1, int* value2){
    int temp = *value1;
    *value1 += *value2;
    *value2 -= temp;
    if(*value2 < 0)
        *value2 = -*value2;
}

int main() {
  // Initialize value1 and value2
  int value1 = 5;
  int value2 = 4;

  // Print values before calling function
  std::cout << "Values before calling function:" << std::endl;
  std::cout << value1 << std::endl;
  std::cout << value2 << std::endl;
  // Call function sum_diff
  sum_difference( & value1, & value2);
  // Print values after calling function
  std::cout << "Values after calling function:" << std::endl;
  std::cout << value1 << std::endl;
  std::cout << value2 << std::endl;

  return 0;
}
