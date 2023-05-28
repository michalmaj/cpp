/*
 * Abstract Class:
 * We can only make derived class's objects to access their functions, and we will never want to instantiate
 * objects of a base class, we call it an abstact class. Such a class exists only to act as a parent of 
 * derived classes that will be used to instantiate objects.
 *
 * How to Write a Pure Virtual Function?
 * It may also provide as interface for the class hierarchy by placing at least one pure virtual function in
 * the base class. A pure virtual function in one with the expression =0 added to the declaration.
 * The equal sign = here has nothing to do with the assignemnt, the value 0 is not assigned to anything. The
 * =0 syntax is simply how we tell the compiler that a virtual function will be pure.
 *
 * Overriding Virtual Function:
 * Once we've placed a pure virtual function in the base class, we must override it in all the derived
 * classes from which we want to instantiate objects. If a class doesn't overrinde the pure virtual
 * function, it becomes an abstract class itself, and we can't instantiate objects from it (although we
 * might from classes derived from it). For consistency, we may want to make all the virtual functions in
 * the base class pure. 
*/
#include <iostream>
#include <numbers> // We need a flag -std=c++20
#include <vector>
// We will use std::reference_wrapper from <functional> header.
// std::reference_wrapper is frequently used as a mechanism to store references inside standard containers,
// like std::vector which cannot normally hold references.
#include <functional> 

// A simple Shape interface which provides a method to get the Shape's area.
class Shape{
public:
    // Just by writinh the keyword virtual we can reference a parent class pointer to child class object.
    virtual float getArea() {return -1;}
};

// A Rectangle is a Shape with a specific width and height
class Rectangle: public Shape{ // derived from Shape class
private:
    float width;
    float height;
    
public:
    Rectangle(float w, float h): width(w), height(h) {}
    
    float getArea() {return width * height;}
};

// A Circle is a Shape with a specific radius
class Circle: public Shape{
private:
    float radius;
    
public:
    Circle(float r): radius(r) {}
    
    float getArea() {return std::numbers::pi * radius * radius;}
};

// A Square is a Shape with a specific length
class Square: public Shape{
private:
    float length;
    
public:
    Square(float l): length(l) {}
    
    float getArea() {return length * length;}
};

int main(){
    // Create an static array of three shapes
    Shape* shape[3];
    
    // Creating three objects of different shapes and put them to the Shape array
    Rectangle r(2, 6);
    shape[0] = &r;
    
    Circle c(5);
    shape[1] = &c;
    
    Square s(10);
    shape[2] = &s;
    
    // Print area of every shape
    for(int i{0}; i < 3; ++i)
        std::cout << shape[i]->getArea() << std::endl;
    
    std::cout << std::endl;
        
    // Using std:vector and std::reference_wrapper to store references of different Shape objectes
    // It allows us to insert references of objects to the container and using polymorhism.
    std::vector<std::reference_wrapper<Shape>> v{r, c, s};
    for(auto& e : v)
        std::cout << e.get().getArea() << std::endl; // Access to method by get()

    return 0;
}
