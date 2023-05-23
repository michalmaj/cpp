/*
 * Multiple Inheritance
 * We can inherit the base class attributes to the derived class if we want derived class to have access
 * data members and member functions of the base class. But to inherit multiple classes data members and 
 * member functions to the derived, the concept of multiple inheritance comes in. We can inherit multiple 
 * classes as base classes spetarated by comma.
*/
#include <iostream>

class Vehicle{
protected:
    std::string Make;
    std::string Color;
    int Year;
    std::string Model;
    
public:
    Vehicle(){
        Make = "";
        Color = "";
        Year = 0;
        Model = "";
    }
    Vehicle(std::string mk, std::string col, int yr, std::string mdl){
        Make = mk;
        Color = col;
        Year = yr;
        Model = mdl;
    }
    void print_details(){
        std::cout << "Manufacturer: " << Make << std::endl;
        std::cout << "Color: " << Color << std::endl;
        std::cout << "Year: " << Year << std::endl;
        std::cout << "Model: " << Model << std::endl;
    }
};

class Car{
    std::string trunk_size;
    
public:
    Car(){
        trunk_size = "";
    }
    Car(std::string ts){
        trunk_size = ts;
    }
    void car_details(){
        std::cout << "Trunk size: " << trunk_size << std::endl;
    }
};

class Honda: public Vehicle, public Car{
    int top_speed;
    
public:
    Honda(){
        top_speed = 0;
    }   
    Honda(std::string mk, std::string col, int yr, std::string mdl, std::string ts, int speed)
    : Vehicle(mk, col, yr, mdl), Car(ts), top_speed(speed){}
    
    void Honda_details(){
        print_details();
        car_details();
        std::cout << "Toop speed of the car: " << top_speed << std::endl;
    }
};

int main(){
    Honda car("Honda", "Black", 2006, "Accord", "14.7 cubic feet", 260);
    car.Honda_details();


    return 0;
}
