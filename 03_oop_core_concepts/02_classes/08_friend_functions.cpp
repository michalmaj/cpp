/*
 * The private data members of a class are only accessible through the functions present in that class.
 * Nothing from outside can manipulate the class object without using its functions.
 * What if we need to access class variables in a function which is not part of the class? That function
 * would have to become a friend of the class.
 * A friend function is an independent function which has access to the variable and methods of its
 * befriended class. To create a friend function for a class, it must be declared in the class along with
 * the friend keyword.
*/
#include <iostream>

class Ball{
    double radius;
    std::string color;
    
public:
    // Constructors
    Ball(){
        radius = 0;
        color = "";
    }
    
    Ball(double r, std::string c): radius(r), color(c){}
    
    // Methods
    void printVolume();
    void printRadius();
    
    // The friend keyword specifies that this is a friend function
    friend void setRadius(Ball& b, double r);
};

// This is a member function that calculates the volume.
void Ball::printVolume(){
    std::cout << (4/3) * 3.142 * radius * radius * radius << std::endl;
}

void Ball::printRadius(){
    std::cout << radius << std::endl;
}

// The implementation of our friend function
void setRadius(Ball& b, double r){
    b.radius = r;
}

int main(){
    Ball b{30, "green"};
    std::cout << "Radius: ";
    b.printRadius();
    setRadius(b, 60);
    std::cout << "New radius: ";
    b.printRadius();
    std::cout << "Volume: ";
    b.printVolume();


    return 0;
}
