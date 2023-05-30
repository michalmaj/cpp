/*
 * Aggregation is very similar to composition. It also follows the Has-A model. This creates a parent-child
 * relationship between two classes, with one class owning the object of another.
 * In aggregation, the lifetime of the owned object does not depend on the lifetime of the owner.
 * The owner object could get deleted but the owned object can continue to exist in the program. In
 * composition, the parent contains a child object. This bounds the child to its parent. In aggregaton, the
 * parent only contains a reference to the child, which removes the child's dependency.
*/
#include <iostream>
#include <memory>

class Country{
    std::string name;
    int population;
    
public:
    Country(std::string n, int p): name(n), population(p) {}
    
    std::string getName() {return name;}
};

class Person{
    std::string name;
    Country* country; // A pointer to a Country object
    
public:
    Person(std::string n, Country* c): name(n), country(c) {}
    
    void printDetails(){
        std::cout << "Name: " << name << std::endl;
        std::cout << "Country: " << country->getName() << std::endl;
    }
};

int main(){
    // 1. Verion with raw pointers
    Country* country = new Country("Poland", 1);
    {
        Person user("Darth Vader", country);
        user.printDetails();
    }
    // The User object lifetime is over
    
    std::cout << country->getName() << std::endl; // The Country object stll exists
    delete country;

    // 2. Version with smart pointers
//    auto country = std::make_unique<Country>("Poland", 1);
//    {
//        Person user("Darth Vader", country.get());
//        user.printDetails();
//    }
    // The User object lifetime is over
    
//    std::cout << country->getName() << std::endl; // The Country object stll exists
    
    return 0;
}
