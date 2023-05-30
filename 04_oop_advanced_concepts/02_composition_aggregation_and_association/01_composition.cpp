/*
 * Composition is accesing other classes objects in your class and owner class owns the object and is
 * responsble for its lifetime. Composition relationship are Part-of relationship where the part must
 * constitute part of the whole object. We can achive composition by addiong smaller parts of other classes 
 * to make a complex unit.
 * Note: In composition, the lifetime of the owned object depends on the lifetime of the owner.
 * Example:
 * A car is composed of an engine, tyres, and doors. In this case, a Car owned these objects so a Car is an
 * Owner class and tyres, doors and engine classes are Owned classes.
*/
#include <iostream>

class Engine{
    int capacity;
    
public:
    Engine(): capacity(0) {}
    Engine(int c): capacity(c) {}
    
    void Engine_details(){
        std::cout << "Engine details: " << capacity << std::endl;
    }
};

class Tyres{
    int No_of_tyres;
    
public:
    Tyres(): No_of_tyres(0) {}
    Tyres(int n): No_of_tyres(n) {}
    
    void Tyre_details(){
        std::cout << "Number of tyres: " << No_of_tyres << std::endl;
    }
};

class Doors{
    int No_of_doors;

public:
    Doors(): No_of_doors(0) {}
    Doors(int n): No_of_doors(n) {}
    
    void Door_details(){
        std::cout << "Number of doors: " << No_of_doors << std::endl;
    }
};

// We are creating a Car class which contains the objects of Engine, Tyres, and Doors classes. Car class
// owns the objects and is responsible for their lifetime. When Car dies, so does tyre, engine and doors 
// too.
class Car{
    Engine Eobj;
    Tyres Tobj;
    Doors Dobj;
    std::string color;

public:
    Car(Engine e, Tyres t, int d, std::string c)
    : Eobj(e), Tobj(t), Dobj(d), color(c) {}
    
    void Car_details(){
        Eobj.Engine_details();
        Tobj.Tyre_details();
        Dobj.Door_details();
        std::cout << "Car color: " << color << std::endl;
    }
};

int main(){
    Engine e(1600);
    Tyres t(4);
    Doors d(4);
    Car c{e, t, 4, "Black"};
    c.Car_details();

    return 0;
}
