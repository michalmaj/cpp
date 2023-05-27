/*
 * The word Polymorphism is a combination of two Greek words, Poly means many and Morph means forms.
 *
 * Definition:
 * Whe we say polymorphism is programming that means something which exhibits many forms or behaviors. So
 * far, we have learned that we can add new data and functions to a class through inheritance. But what
 * about if we want our derived class to inherit a method from the base class and have a different 
 * implementation for it? That is when polymorphism comes in, a fundamental concept in OOP paradigm.
 *
 * Example:
 * We are considering here the example of Shape class, which is base class from many shapes like Rectangle
 * and Circle. This class contains a function getArea() which calculates the area for the derived classes.
 * Consider the REctangle class which is derived from Shape class. It has two data members, i.e., width and
 * height and it returns the Area of the rectangle by using getArea() function.
 * Consider the CIrcle class which is derived from Shape class. It has one data member, i.e., radius and it
 * returns the Area of the circle by using getArea() function.
*/
#include <iostream>

// A simple Shape interface which provides a ethod to get the Shape's area
class Shape{
public:
    float getArea() {return -1;}
};

// A rectangle is a Shape with a specific width and height
class Rectangle: public Shape{ // derived from Shape class
private:
    float width;
    float height;

public:
    Rectangle(float w, float h): width(w), height(h) {}
    
    float getArea(){
        return width * height;
    }
};

// A circle is a Shape with a specific radius
class Circle: public Shape{
private:
    float radius;
    
public:
    Circle(float r): radius(r) {}
    
    float getArea(){
        return 3.14159f * radius * radius;
    }
};

int main(){
    /*
     * Polymorphism only works with a pointer and reference types, so we have created a Shape pointer, and
     * pointed to the derived class objects. But due to multiple existence of the same functions in classes,
     * it will get confused between which class getArea() function it's calling. The derived class fucntion
     * has a different implementation but the same name and that's why we are not getting the expected
     * output.
    */
    Rectangle r(2, 6);    // Creating Rectangle object

    Shape* shape = &r;   // Referencing Shape class to Rectangle object

    std::cout << "Calling Rectangle getArea function: " << r.getArea() << std::endl;
    std::cout << "Calling Rectangle from shape pointer: " <<  shape->getArea() << std::endl << std::endl;

    Circle c(5);    // Creating Circle object

    shape = &c;   // Referencing Shape class to Circle object

    std::cout << "Calling Circle getArea function: " << c.getArea() << std::endl;
    std::cout << "Calling Circle from shape pointer: " <<shape->getArea() << std::endl << std::endl; 
    return 0;
}
