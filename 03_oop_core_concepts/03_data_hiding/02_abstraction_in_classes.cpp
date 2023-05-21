/*
 * Abstraction is the second component of data hiding in OOP. It is an extension of encapsulation and 
 * further simplifies the structure of programs.
 * Abstarction focuses on revealing only the relevant parts of the application while keeping the inner
 * implementation hidden.
 * For example users will perform actions and expect the application to respond accordingly. They will not
 * be concered with how to response in generated. Only the final outcome is relevant.
*/
#include <iostream>
#include <numbers> // C++20, g++ -std=c++20

class Circle{
    double radius;
    double pi;
    
public:
    // Constructors
    Circle(): radius(0), pi(std::numbers::pi){}
    Circle(double r): radius(r), pi(std::numbers::pi){}
    
    // Methods
    double area() {return pi * radius * radius;}
    double perimeter() {return 2 * pi * radius;}
};

int main(){
    Circle c(5);
    std::cout << "Area: " << c.area() << std::endl;
    std::cout << "Perimeter: " << c.perimeter() << std::endl;

    return 0;
}
