/*
 * You are gven a radius r of the sphere. Your task is to find the area of the sphere using the
 * following formula: Area = 4 * pi * r^2. Data: double r = 10.9;
*/

#include <iostream>

int main(){
    const double PI = 3.14;
    double r = 10.9;
    double area = 4 * PI * r * r;
    
    std::cout << "The area of our sphere is: " << area << "\n";

    return 0;
}
