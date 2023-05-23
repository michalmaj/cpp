/*
 * If we want to inherit data members and member functions of the base class which is already inherit from
 * another class, the concept of multilevel inheritance comes in. This contains a more hierarchical approach
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
    Vehicle(std::string mk, std::string col, int yr, std::string mdl)
    : Make(mk), Color(col), Year(yr), Model(mdl) {}
    
    void print_details(){
        std::cout << "Manufacturer: " << Make << std::endl;
        std::cout << "Color: " << Color << std::endl;
        std::cout << "Year: " << Year << std::endl;
        std::cout << "Model: " << Model << std::endl;
    }
};

class Car: public Vehicle{
    std::string trunk_size;
    
public:
    Car()
    : trunk_size{""} {}
    Car(std::string mk, std::string col, int yr, std::string mdl, std::string ts)
    : Vehicle(mk, col, yr, mdl), trunk_size(ts) {}
    
    void car_details(){
        std::cout << "Trunk size: " << trunk_size << std::endl;
    }
};

class Honda: public Car{
    int top_speed;
    
public:
    Honda()
    : top_speed{0} {}
    Honda(std::string mk, std::string col, int yr, std::string mdl, std::string ts, int speed)
    : Car(mk, col, yr, mdl, ts), top_speed{speed} {}
    
    void Honda_details(){
        print_details();
        car_details();
        std::cout << "Top speed of the car: " << top_speed << std::endl;
    }
};

int main(){
    Honda car("Honda", "Black", 2006, "Accord", "14.7 cubic feet", 260);
    car.Honda_details();

    return 0;
}
