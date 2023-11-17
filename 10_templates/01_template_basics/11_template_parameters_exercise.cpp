/*
 * Problem statement
 * Implement four different class template which accept an integral, a pointer, a reference, or a nullptr as non-type
 * parameter. YOu need to display the type of data passed as a parameter.
 */
#include <cstddef>
#include <iostream>
#include <typeinfo>

// Write class templates for given commented code

// AcceptChar<'c'> acceptChar
template <char c>
class AcceptChar{
public:
    AcceptChar(){
        std::cout << "AcceptChar: " << typeid(c).name() << std::endl;
    }
};

// AcceptFunction< myFunc> acceptFunction
template <int (*func)(int)>
class AcceptFunction{
public:
    AcceptFunction(){
        std::cout << "AcceptFunction: " << typeid(func).name() << std::endl;
    }
};

// AcceptReference< arr > acceptReference
template <int (&arr)[5]>
class AcceptReference{
public:
    AcceptReference(){
        std::cout << "AcceptReference: " << typeid(arr).name() << std::endl;
    }
};

// AcceptNullptr< nullptr > acceptNullptr
template <std::nullptr_t N>
class AcceptNullptr{
public:
    AcceptNullptr(){
        std::cout << "AcceptNullptr: " << typeid(N).name() << std::endl;
    }
};

int myFunc(int){return 2023;}
int arr[5]{};


int main() {

    std::cout << std::endl;

    AcceptChar<'c'> acceptChar;
    AcceptFunction<myFunc> acceptFunction;
    AcceptReference<arr> acceptReference;
    AcceptNullptr<nullptr> acceptNullptr;

    return 0;
}