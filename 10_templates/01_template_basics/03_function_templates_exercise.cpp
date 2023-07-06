/*
 * We have to implement a function which calculates 2^10 in the program. Try using templates to implement
 * the function.
*/
#include <iostream>

// Solution 1: Using Function Arguments
// We're using a for loop to compute the power. The loop runs a total of n times by multiplying the
// number m with r for every iteration of the loop.
int power1(int m, int n){
  int r = 1;
  for(int k=1; k<=n; ++k) 
      r *= m;
  return r;
}

// Solution 2: Using Template Arguments
// First, the primary template is called. Then the Power2<m, n-1>::value executed.
// This expression instantiates recursively until the end condtion is met (n is equal to 0).
template <int m, int n>
struct Power2{
  static int const value = m * Power2<m, n-1>::value;
};
// Recursion base case
template <int m>
struct Power2<m, 0>{ 
  static int const value = 1;
};

// Solution 3: Using Template Arguments and Function Arguments
// In this case the power function template exists in three variations. First the primary template below.
// Second and third in the full specializations for 1 and 0 are below.
template <int n>
int power3(int m){
  return m * power3<n-1>(m);
}

template<>
int power3<1>(int m){
  return m;
}

template<>
int power3<0>(int m){
  return 1;
}



int main() {
  std::cout << "Solution1: " << power1(2, 10) << std::endl;
  
  // The call Power2<2, 10>::value triggers the recursive calculation.
  std::cout << "Solution2: " << Power2<2, 10>::value << std::endl;

  // The call power3<10>(2) triggers the recursive invocation of the primary template.
  std::cout << "Solution3: " << power3<10>(2) <<std::endl;
}
