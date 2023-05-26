/*
 * In this challenge, we'll implemnt a base class Animal and two derived classes Sheep and Dog.
 * Problem Statement:
 * A parent class named Animal. Inside it define:
 *  - Name;
 *  - Sound;
 *  - void Animal_Details() function, it prints the name and sound of the Animal.
 * Then there are two derived classes:
 * Dag class:
 *  - has a private member family
 *  - has a function named Dog_detail() whch printes details of the Dog.
 * Sheep class:
 *  - has a private member color
 *  - has a function Sheep_detail()
 * The derived classes should call the method of the Animal class which prints the name and the sound for 
 * Dog family of dog that is Carnivores and for Sheep class prints the color of sheep White.
*/
#include <iostream>

// Write classes code here
class Animal{
protected:
    std::string name;
    std::string sound;
    
public:
    Animal(): name(""), sound("") {}
    Animal(std::string n, std::string s): name(n), sound(s) {}
    
    void Animal_Details(){
        std::cout << "Animal Name : " << name << std::endl;
        std::cout << "Animal Sound : " << sound << std::endl;
    }
};

class Dog: public Animal{
    std::string family;

public:
    Dog(): family("") {}
    Dog(std::string n, std::string s, std::string f="Carnivores")
    : Animal(n, s), family(f) {}
    
    void Dog_detail(){
        Animal_Details();
        std::cout << "Dog's Family : " << family << std::endl;
    }
};

class Sheep: public Animal{
    std::string color;
    
public:
    Sheep(): color("") {}
    Sheep(std::string n, std::string s, std::string c="White")
    : Animal(n, s), color(c) {}
    
    void Sheep_detail(){
        Animal_Details();
        std::cout << "Sheep Color : " << color << std::endl;
    }
};


int main() {
    // Make classes objects here
    Dog d("Pongo", "Woof Woof");
    d.Dog_detail();
    
    Sheep s("Billy", "Baaa Baaa");
    s.Sheep_detail();
  
  return 0;
}
