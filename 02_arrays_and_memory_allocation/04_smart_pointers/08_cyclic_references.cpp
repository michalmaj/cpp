/*
 * We get cyclic references of std::shared_ptr if they refer to each other.
 * If we have a cyclic reference of std::shared_ptr, the reference counter will never become 0. We can 
 * break this cycle if by embedding an std::weak_ptr in the cycle. std::weak_ptr does not modify the
 * reference counter.
*/

#include <iostream>
#include <memory>

struct Son;
struct Daughter;

struct Mother{
    ~Mother(){
        std::cout << "Mother gone\n";
    }
    
    void setSon(const std::shared_ptr<Son> s){
        mySon = s;
    }
    
    void setDaughter(const std::shared_ptr<Daughter> d){
        myDaughter = d;
    }
    std::shared_ptr<const Son> mySon;
    std::weak_ptr<const Daughter> myDaughter;
};

struct Son{
    Son(std::shared_ptr<Mother> m) : myMother(m){}
    ~Son(){
        std::cout << "Son gone\n";
    }
    std::shared_ptr<const Mother> myMother;
};

struct Daughter{
    Daughter(std::shared_ptr<Mother> m) : myMother(m){}
    ~Daughter(){
        std::cout << "Daughter gone\n";
    }
    std::shared_ptr<const Mother> myMother;
};


int main(){
    // After this scope, the lifetime of the mother, the son, and the daughter are limited.
    // Inother words, mother, son, and daughter go out of scope, and therefore the destructor
    // of the class Mother, Son, and Daughter should automatically be invoked.
    // But in this case only the destructor of the class Daughter is called. Because we have a
    // cyclic reference between mother and son. Therefore, the reference counter is always
    // greater than 0, and the destructor will not automatically be invoked.
    {
        std::shared_ptr<Mother> mother = std::make_shared<Mother>();
        std::shared_ptr<Son> son = std::make_shared<Son>(mother);
        std::shared_ptr<Daughter> daughter = std::make_shared<Daughter>(mother);
        mother->setSon(son);
        mother->setDaughter(daughter);
    }
    std::cout << std::endl;


    return 0;
}
