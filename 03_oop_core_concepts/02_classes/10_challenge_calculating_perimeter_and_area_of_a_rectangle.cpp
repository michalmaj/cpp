/*
 * Write a Rectangle class having two float type variables for length and height, a parametrized constructor
 * and two member functions called perimeter and area which return perimeter and area of the rectangle
 * respectively.
 * Input: length and width of the rectangle.
 * Output: Perimeter and area of rectangle.
*/
#include <iostream>

class Rectangle {

public:
    // Add public data members, a constructor, and member functions
    Rectangle(float l, float h): length(l), height(h){}
    
    float length;
    float height;


    float perimeter() {
        float answer; 
        // write your code here to calculate the perimeter of the rectangle 
        // using the length and height variable
        answer = 2*length + 2*height;

    // Store rectangle perimeter in answer
    return answer;
}

    float area() {
        float answer; 
        // write your code here to calculate the area of the rectangle 
        // using the length and height variable
        answer = length * height;
    // Store rectangle area in answer
    return answer;
    }
};

int main(){
    Rectangle r1{10.0, 20.0};
    std::cout << "Perimeter: " << r1.perimeter()
    << ", area: " << r1.area() << std::endl;




    return 0;
}
