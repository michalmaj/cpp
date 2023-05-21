/*
 * You have to implement a class called Point that represents a specific point in the x-y plane. It should
 * contain the following:
 * fields:
 *  x (int type)
 *  y (int type)
 * methods:
 *  default constructor that initializes the point at (0, 0).
 *  parametrized constructor that takes input x and y and initializes the point to the respective
 *  coordiantes.
 *  float distance(), a method which calculates the distance of the point (represented by the object) from
 *  the origin, i.e. (0, 0)
 *  float distance(int x1, int y1), a method which calculates the distance between the point represented
 *  by the class object and (x1, y1).
 * The distance between two points (x, y) and (x1, y1) can be calculated by the following formula:
 *      distance = sqrt((x1 - x)^2 + (y1 - y)^2)  
*/
#include <iostream>
#include <cmath>

class Point {
// Private fields
private:
    int x;
    int y;

public:

    // Default Constructor
    Point() {
        x = 0;
        y = 0;
    }

    // Parameterized Constructor
    Point(int x, int y) { 
        // Implement the function
        this->x = x;
        this->y = y;
    }


    double distance() {
        // Implement the function
        return sqrt(pow(x - 0, 2) + pow(y - 0, 2)) ;
    }

    double distance(int x2, int y2) {
        // Implement the function
        return sqrt(pow(x2 - x, 2) + pow(y2 - y, 2));
    }
};


int main(){

    Point p1 = Point(5, 5);
    
    std::cout << p1.distance() << std::endl;
    std::cout << p1.distance(2, 1) << std::endl;


    return 0;
}
