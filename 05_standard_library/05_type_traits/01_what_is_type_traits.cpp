/*
 * The type traits library enables us to check, compare and modify types at compile time. So, there is no
 * overheaded on the runtime of our program. There are two reasons for using the type traits library:
 *  1. Optimization, because the introspection capabilities of the type traits library make it possible
       to choose the faster code automatically.
 *  2. Correctness, because we can specify requirements for our code, which is checked at compile time.
 *
 * Type traits library and static_assert are a powerful pair:
 * On one sied, the functions of the type traits library provide the type information at compile time. On 
 * the side, the static_assert function checks the given information at compile time.
 *
 * Primary Tye Categories
 * There are 14 different type categories. They are complete and don't overlap. So each type is only a 
 * member of one type category. If we check a type category for our type, the request is independent of the
 * const or volatile qualifiers.
 *  template <class T> struct is_integral; 
 *  template <class T> struct is_floating_point; 
 *  template <class T> struct is_void;
 *  template <class T> struct is_null_pointer;
 *  template <class T> struct is_array;
 *  template <class T> struct is_pointer;
 *  template <class T> struct is_member_object_pointer;
 *  template <class T> struct is_member_function_pointer;
 *  template <class T> struct is_enum;
 *  template <class T> struct is_union;
 *  template <class T> struct is_class;
 *  template <class T> struct is_function;
 *  template <class T> struct is_lvalue_reference;
 *  template <class T> struct is_rvalue_reference; 
*/
#include <iostream>
#include <type_traits>

int main(){
    std::cout << std::boolalpha;
    
    std::cout << "is_void: " << std::is_void<void>::value << "\n";
    std::cout << "is_integral: " << std::is_integral<short>::value << "\n";
    std::cout << "is_floating_point: " << std::is_floating_point<double>::value << "\n";
    std::cout << "is_aray: " << std::is_array<int[]>::value << "\n";
    std::cout << "is_pointer: " << std::is_pointer<int*>::value << "\n";
    std::cout << "is_reference: " << std::is_reference<int&>::value << "\n";
    
    struct A{
        int a;
        int f(int){return 2023;}
    };
    std::cout << "is_member_object_pointer: " << std::is_member_object_pointer<int A::*>::value << "\n";
    std::cout << "is_member_function_pointer: " 
    << std::is_member_function_pointer<int (A::*)(int)>::value << "\n";
    
    enum E{
        e = 1,
    };
    std::cout << "is_enum: " << std::is_enum<E>::value << "\n";
    
    union U{
        int u;
    };
    std::cout << "is_union: " << std::is_union<U>::value << "\n";
    
    std::cout << "is_class: " << std::is_class<std::string>::value << "\n";
    std::cout << "is_function: " << std::is_function<int* (double)>::value << "\n";
    std::cout << "is_lvalue_reference: " << std::is_lvalue_reference<int&>::value << "\n";
    std::cout << "is_rvalue_reference: " << std::is_rvalue_reference<int&&>::value << "\n";


    return 0;
}

