/*
 * Problem Statement
 * Make the public member elem a private member of Array. How does that affect the
 * implementation of the assignment operator?
*/
#include <algorithm>
#include <iostream>
#include <vector>

// We are creating an Array class in whch we are defining an operator= which copies the integer array 
// to double array.
// getSize() function returns the size of the array passed in the argumnet. Template classes with
// different template argumnets are considered of different types, which is why Array<int, 10> and 
// Array<double, 10> aren't able to access each other.
// And that's why the Array template class has to be declared a friend of itself.
// To access the private elem of arr in line 29, class Arrays is a friend if the class Array in line 23.
template <typename T, int N>
class Array{

public:
  Array()= default;

  template <typename T2, int M> friend class Array;

  template <typename T2>
  Array<T, N>& operator=(const Array<T2, N>& arr){
	  static_assert(std::is_convertible<T2, T>::value, "Cannot convert source type to destination type!");
    elem.clear();
	  elem.insert(elem.begin(), arr.elem.begin(), arr.elem.end());
	  return *this;
  }

  int getSize() const;
  // you need to make the `elem` private and then run it
private:
  std::vector<T> elem;
};

template <typename T, int N>
int Array<T, N>::getSize() const {
  return N;
}


int main(){

  // uncomment these line after the above implementation
  Array<double, 10> doubleArray{};
  Array<int, 10> intArray{};

  doubleArray = intArray;


  return 0;
}
