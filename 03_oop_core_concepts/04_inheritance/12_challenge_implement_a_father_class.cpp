/*
 * We'll implement a base class father and derived classes, sond and daughter.
 * Problem Statement:
 * A parent class named Father:
 *  Inside it define:
 *  - eye_color;
 *  - hair_color;
 *  - void Father_traits() function - it prints the eye_color of the called object
 * Then, there are two derived classes:
 *  Son class:
 *  - has a private member name
 *  - has a function named Son_traits()
 *  Daughter class:
 *  - has a private member name
 *  - has a function named Daughter_traits()
 * The derived classes should call the method of the Father class which prints the eye_color and the
 * hair_color and for Son and Daughter classes prints the name of a respective object.
 * Daughter obj("Rapunzel","Green","Golden");
 * obj.Daughter_traits();
 * Son Obj("Ralph","Brown","Black");
 * Obj.Son_traits();
*/
#include <iostream>

// Write your classes here
class Father{
    std::string eye_color;
    std::string hair_color;
    
public:
    Father(): eye_color(""), hair_color("") {}
    Father(std::string eye, std::string hair): eye_color(eye), hair_color(hair) {}
    void Father_traits(){
        std::cout << "Eye color: " << eye_color << std::endl;
        std::cout << "Hair color: " << hair_color << std::endl;
    }
};

class Daughter: public Father{
    std::string name;

public:
    Daughter(): name("") {}
    Daughter(std::string n, std::string eye, std::string hair)
    : name(n), Father(eye, hair) {}
    
    void Daughter_traits(){
        Father_traits();
        std::cout << name << " has long hair!\n";
    }
};

class Son: public Father{
    std::string name;
    
public:
    Son(): name("") {}
    Son(std::string n, std::string eye, std::string hair)
    : name(n), Father(eye, hair) {}
    
    void Son_traits(){
        Father_traits();
        std::cout << name << " has beard!\n";
    }
};

int main() {
    // create classes objects here
    // call derived class member functions here
    Daughter obj("Rapunzel","Green","Golden");
    obj.Daughter_traits();

    std::cout << std::endl;

    Son Obj("Ralph","Brown","Black");
    Obj.Son_traits();
  return 0;
}
