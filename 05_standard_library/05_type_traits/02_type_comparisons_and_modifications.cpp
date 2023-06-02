/*
 * Sometimes we need to manipulate or compare different types. We can use the type ttraits library for that.
 * 
 * Type Comparison
 * The library supports three kinds of type comparisons:
 *  1. Check if Derived is derived from Base.
 *  2. Checks if From can be converted to To.
 *  3. Checks if the types T and U are the same.
 *
 * Type Modifications
 * The type traits library enables us to modify types during complie time. So we can modify the constness of
 * a type.
 *
 * We have a lot functions available in the type traits library.
 * 
 * We can modify the const-volatile propertis of a type:
 *  template <class T> struct remove_const;
 *  template <class T> struct remove_volatile;
 *  template <class T> struct remove_cv;
 *  template <class T> struct add_const;
 *  template <class T> struct add_volatile;
 *  template <class T> struct add_cv;
 *
 * We can change at compile tme the sign:
 *  template <class T> struct make_signed;
 *  template <class T> struct make_unsigned;
 *
 * We can change at copile time the reference or poiter properties of a type.
 *  template <class T> struct remove_reference;
 *  template <class T> struct add_lvalue_reference;
 *  template <class T> struct add_rvalue_reference;
 *  template <class T> struct remove_pointer;
 *  template <class T> struct add_pointer;
*/
#include <iostream>
#include <type_traits>

int main(){
    std::cout << std::boolalpha;
    
    std::cout << "is_const<int>: " << std::is_const<int>::value << "\n";
    std::cout << "is_const<const int>: " << std::is_const<const int>::value << "\n";
    
    typedef std::add_const<int>::type myConstInt;
    std::cout << "is_const<myConstInt>: " << std::is_const<myConstInt>::value << "\n";
    
    typedef const int myConstInt2;
    std::cout << "is_same<myConstInt, myConstInt>: " << std::is_same<myConstInt, myConstInt>::value << "\n";
    
    // The function std::add_const adds the constness to a type, wjile std::remove_const removes it
    std::cout << "is_same<int, std::remove_const<std::add_const<int>::type>::type>: "
    << std::is_same<int, std::remove_const<std::add_const<int>::type>::type>::value << "\n";
    
    std::cout << "is_same<const int, std::add_const<int>::type>: " 
    << std::is_same<const int, std::add_const<int>::type>::value << "\n";

    return 0;
}
