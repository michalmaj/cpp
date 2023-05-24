/*
 * Implement a function getDetails(std::string carName) of the Derived Class Car which takes a string
 * carName and append it with model name and speed.
*/
#include <iostream>

// Base class
class Vehicle{
    std::string speed;
    std::string model;
    
public:
    Vehicle() {
        speed = "";
        model = "";
    }
    Vehicle(std::string s, std::string m): speed(s), model(m) {}
    std::string getSpeed(){return speed;}
    std::string getModel(){return model;}
    void setSpeed(std::string s){speed = s;}
    void setModel(std::string m){model = m;}
};

// Derived Class
class Car: public Vehicle { // This line needs to be changed.
  
  std::string name; //  Name of a Car
  
  public:
  Car() { // Default Constructor
    name = "";
  }
  
  // This function sets the name of the car
  void setDetails(std::string name) { // Setter Function
    this->name = name;
  }
  
  // This function calls the Base class functions and appends the result with the input 
  std::string getDetails(std::string carName) { 
    
    std::string details = "";
    
    // write your code here
    details = carName + ", "+ getModel() + ", " + getSpeed();
    
    return details;
  } 
};



int main(){
    Car c;
    c.setSpeed("100");
    c.setModel("Tesla");
    
    std::cout << c.getDetails("Roadster") << std::endl;


    return 0;
}
