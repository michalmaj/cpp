/*
 * Constructor delegation occurs when a constructor calls another constructor of the same class in its
 * initializer list.
 * Rules:
 *  - When constructor call in the initializer list completed, the object is created. This object can then
 *    be altered in the calling constructor's body.
 *  - It is important to perform constructor delegation in the initializer list. If it called in the body,
 *    a new class object will be created and we will end up with two objects, which is not the behavior
 *    we want.
 *  - Recursively invoking constructors will result in undefined behavior.
 *
 * The aim of delegation is to let one constructor handle initialization. That object can be used or 
 * modified by all other constructors. In other words, constructors can delegate the task of object creation
 * to other constructors.
 * A greeat  adventage of constructor delegation is that the initialization code is localzed. Once that code
 * has been tested, the rest of the code can be built upon it robustly. Also, bugs, if there are any, will
 * be localized to the specific constructor(s) instead of being spread all over the place.
*/
#include <iostream>
#include <cmath>

class MyHour{
public:
    MyHour(int hour){
        if(0 <= hour and hour <= 23)
            myHour = hour;
        else
            myHour = 0;
            
        std::cout << "myHour: " << myHour << std::endl;
    }
    MyHour(): MyHour(0){}
    MyHour(double hour): MyHour(static_cast<int>(ceil(hour))){}
private:
    int myHour;
};


int main(){
    
    std::cout << std::endl;

    MyHour(10);
    MyHour(100);
    MyHour();
    MyHour(22.45);

    std::cout << std::endl;


    return 0;
}
