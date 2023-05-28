/*
 * Overriding:
 * In object-oriented programming when we allow a subclass or child class to provide a specific
 * implementation of a method that is already provided by one of its superclass or parent classes is know as
 * Function Overriding.
 * Advantages of the Method Overriding:
 * Method overriding is very useful is OOP and have many adventages. Some of them are:
 *  - The derived classes can give its own specific implementation to inherited methods without modifying
 *    the parent class methods.
 *  - If a child class needs to use the parent class method, it can use it, and the other classes that want
 *    to have different implementation can use the overriding feature to make changes.
 * Key features of Overriding:
 * Here some key features of the Method Overriding:
 *  - Overriding needs inheritance and ther should be at least one derived class.
 *  - Derived class/es must hav e the same declaration, i.e., name, same parameters and same return type of
 *    the function as of the base class.
 *  - The function is derived class/es must have different implementation from each other.
 *  - The method in the base class must need to be overriden in the derived class.
 *
 * Virtual Member Functions:
 * A virtaul function is  a memebr function which is declared within the base class and is overriden by the
 * derived class. When we refer to a derived class object using a pointer or a reference to the base class,
 * you can call a virtual function for that object and execute the derived class's version of the function.
 * Virtual functons ensure that the correct function is called for an object, regardless of the type of
 * reference (or pointer) used for the function call. They are mainly used to achieve Runtime polymorphism.
 * Functions are declared with a virtual keyword in a base class. The function resolution call is done at
 * run-time.
 * Why Do We Need a Virtual Function?
 * Suppose we have a number of objects of different classes like in ths case, we have multiple shapes
 * classes. We want to put them all in an array and perform a particular operation on them using the same
 * function call. For example, we want to access the same function getArea() from multiple child classes.
*/
#include <iostream>
#include <numbers> // We need a flag -std=c++20

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

int main(){
    Rectangle r{2, 6}; // Creating Rectangele object
    Shape* shape = &r; // Referencing Shape class to Rectangle object
    // Call shape's dynamically
    std::cout << "Calling Rectangle from shape pointer: " << shape->getArea() << std::endl;
    
    std::cout << std::endl;
    
    Circle c(5); // Creating Circle object
    shape = &c; // Referencing Shape class to Circle object
    // Call shape's dynamically
    std::cout << "Calling Circle from shape pointer: " << shape->getArea() << std::endl;

    return 0;
}
