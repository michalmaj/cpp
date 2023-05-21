#ifndef CIRCLE_H
#define CIRCLE_H

// Declare all the members of the class here
class Circle{
    double radius;
    double pi;
    
public:
    // Constructors
    Circle();
    Circle(double r);
    
    // Methods
    double area();
    double perimeter();
};


#endif
