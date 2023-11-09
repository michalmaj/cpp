// Overloading function templates

#include <iostream>

void xchg(int& x, int& y){ // 1
    int t = x;
    x = y;
    y = t;
}

template <typename T>
void xchg(T& x, T& y){ // 2
    T t = x;
    x = y;
    y = t;
}

template <typename T>
void xchg(T& x, T& y, T& z){ // 3
    xchg(x, y);
    xchg(x, z);
}

int main(){
    std::cout << "\n";

    int intA{5};
    int intB{10};
    int intC{20};

    double doubleA{5.5};
    double doubleB{10.0};

    std::cout << "Before: " << intA << ", " << intB << "\n";
    xchg(intA, intB); // 1
    std::cout << "After: " << intA << ", " << intB << "\n";

    std::cout << "\n";

    std::cout << "Before: " << doubleA << ", " << doubleB << "\n";
    xchg(doubleA, doubleB); // 2
    std::cout << "Before: " << doubleA << ", " << doubleB << "\n";

    std::cout << "\n";

    xchg<>(intA, intB); // explicit 2
    xchg<int>(intA, intB); // explicit 2: xchg<int>
//    xchg<double>(intA, intB); // CE: templates do not support an automatic type conversion (here: int to double)

    std::cout << "Before: " << intA << ", " << intB << ", " << intC << std::endl;
    xchg(intA, intB, intC); // 3
    std::cout << "After: " << intA << ", " << intB << ", " << intC << std::endl;

    return 0;
}