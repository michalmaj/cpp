/*
 * Write a C++ class called Student with:
 * private member variables:
 *  name (string type)
 *  mark1 and mark2 (float type)
 * public member functions and constructors
 *  get_marks(int marknumber), a function which should return mark1 if marknumber equals 1 and mark2 
 *  otherwise.
 *  calc_total() function should take two marks entered and return their sum.
 *  A dafault constructor that takes no parameters and initializes the values to zeros and empty string.
 *  A constructor that takes the three variables and sets them to given values.
*/
#include <iostream>

class Student
{
    // write class member variables here
    std::string name;
    float mark1;
    float mark2;

public:
    // Constructor with no arguments (default constructor)
    Student() {
    //write definition here
    name = "";
    mark1 = 0;
    mark2 = 0;
    }

    // Constructor with three arguments
    Student(std::string na, float ma1,float ma2) {
    //write definition here
    name = na;
    mark1 = ma1;
    mark2 = ma2;
    }

    float GetMarks(int marknumber) {
    //write definition here
    return (marknumber == 1)? mark1 : mark2;
    }

    float calc_total() {
    //write definition here
    return mark1 + mark2;
    }
};

int main(){
    Student s1{"Jack", 60, 70};
    std::cout << "GetMarks(1): " << s1.GetMarks(1) << "\n";
    std::cout << "GetMarks(2): " << s1.GetMarks(2) << "\n";
    std::cout << "calc_total(): " << s1.calc_total() << "\n";
    


    return 0;
}
