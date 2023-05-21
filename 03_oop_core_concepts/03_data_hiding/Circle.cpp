#include <numbers> // C++20, g++ -std=c++20
#include "Circle.h"

// Constructors
Circle::Circle(): radius(0), pi(std::numbers::pi){}
Circle::Circle(double r): radius(r), pi(std::numbers::pi){}

// Methods
double Circle::area() {return pi * radius * radius;}
double Circle::perimeter() {return 2 * pi * radius;}
