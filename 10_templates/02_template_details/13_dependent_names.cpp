/*
 * A dependent names s essentially a name that depends on a template parameter. A dependent name can be a
 * type, a non-type, or a template-template parameter.
 * If we use a dependent name in a template declaration or template definition, the compiler has no idea, 
 * whether this name refers to a type, a non-type, or a template parameter. In this case, the compiler 
 * assumes that the dependent name refers to a non-type, which may be wrong.
 * Let's have a look at the example of dependent names:
 *  template <typename T>
 *  struct X : B<T> // B<T> is dependent on T
 *  {
 *    typename T::A* pa; // T::A is dependenton T 
 *    voif f(B<T>* pb){
 *      static int i = B<T>::i; // B<T>::i is dependent on T 
 *      pb->j++; // pb->j is dependent on T 
 *    }
 *  }
 * T is the template parameter. The names B<T>, T::A, B<T>, B<T>::i, and pb->j are dependent.
 *
 * Two-phase name lookup:
 *  - Dependent names are resolved during template instantiation.
 *  - Non-dependent names are resolved during template definition.
 * 
 * A from a template parameter T is dependent, qualified name T::A can be:
 *  - Type 
 *  - Non-type 
 *  - Template 
 * Note: the compiler assumes by default that T::A is a non-type.
 * The compiler has to be convinced thet T::A is a type or a template.
 *
 * The Dependent Name is a Type typename:
 *  template <typename T> void test(){
 *    std::vector<T>::const_iterator* p1; // Error
 *    typename std::vector<T>::const_iterator* p2; // OK
 *  }
 * Wthout typename like in line 33, the expression in line 32 would be interpreted as multiplication.
 *
 * The Dependent Name is a Template .template
 *  template <typename T>
 *  struct S{
 *    template <template U> void func() {}
 *  }
 *
 *  template <typename T>
 *  void func2(){
 *    S<T> s;
 *    s.func<T>; // Error
 *    s.template func<T>();
 *  }
 * Compare line 46 and 47. When the compiler reads the name s.func (line 46), it decides to interpret is 
 * as non-type. This means, the < sign stands in this case for the comparison operator but not opening 
 * square bracket of the template argument of the generic method func. To help the parser, we have to 
 * specify that s.func is a templatelike in line 47: s.template func.
*/
#include <iostream>

// If we have access the defined function g with double or int type object, they work fine.
void g(double) { std::cout << "g(double)\n"; }

template <typename T>
struct S{
  void f() const {
    g(1); // non-dependent 
  }
};

void g(int) { std::cout << "g(int)\n"; }

int main(){
  g(1); // calls g(int) 

  // We are creating here a struct object s of int type.
  S<int> s;
  s.f(); // calls g(double)

  return 0;
}
