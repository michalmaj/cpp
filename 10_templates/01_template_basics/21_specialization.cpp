/*
 * Template Specialization Type Traits.
 * In this example we are going to use to type_traits library which detects at compile-time to which 
 * primary category value belongs to. The primary type categories are complete and exclusive. This means
 * each type belongs exactly t one primary type category. For example, void return true for the 
 * type-trait std::is_void and fale for all the other type categories.
*/
#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
void getPrimaryTypeCategory(){

  cout << boolalpha << endl;

  cout << "is_void<T>::value: " << is_void<T>::value << endl;
  cout << "is_integral<T>::value: " << is_integral<T>::value << endl;
  cout << "is_floating_point<T>::value: " << is_floating_point<T>::value << endl;
  cout << "is_array<T>::value: " << is_array<T>::value << endl;
  cout << "is_pointer<T>::value: " << is_pointer<T>::value << endl;
  cout << "is_reference<T>::value: " << is_reference<T>::value << endl;
  cout << "is_member_object_pointer<T>::value: " << is_member_object_pointer<T>::value << endl;
  cout << "is_member_function_pointer<T>::value: " << is_member_function_pointer<T>::value << endl;
  cout << "is_enum<T>::value: " << is_enum<T>::value << endl;
  cout << "is_union<T>::value: " << is_union<T>::value << endl;
  cout << "is_class<T>::value: " << is_class<T>::value << endl;
  cout << "is_function<T>::value: " << is_function<T>::value << endl;
  cout << "is_lvalue_reference<T>::value: " << is_lvalue_reference<T>::value << endl;
  cout << "is_rvalue_reference<T>::value: " << is_rvalue_reference<T>::value << endl;

  cout << endl;

}

int main(){
    getPrimaryTypeCategory<void>();
}
