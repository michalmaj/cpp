/*
 * When implementing multiple inheritance, we might run into a problem known as the diamond problem. The 
 * diamond problem occurs when a derived class inherits the same member from multiple parent classes. This
 * causes ambiguity for the compiler.
*/
#include <iostream>

/*
 * In the below above code example, f we replace return ID with either return B::ID, or return C::ID, the 
 * program would compile and run fine. All that does in explicitly tell the compiler to fetch the value of
 * the member named ID from class B or class C, depending which solution we use.
 * However, ther are still two copies of the ID member in this program. This may be OK for a simple program,
 * but wouldn't be acceptable in larger programs.
 * Best solution to the diamond problem is to use virtual inheritance.
 * With virtual inheritance, only one instance of the base class A is inherited into the derived class D.
*/
class A{
protected:
    int ID;
    
public:
    A(): ID(0) {}
};

class B: virtual public A{
public:
    int length;
};

class C: virtual public A{
public:
    int radius;
};

/*
 * Notice that without anychanges compiler complains that in class D, the member ID is ambigous. Both of its
 * parent classes, B and C have that member. Hence a dilema for the compiler.
 * CLass B gets its copy of the ID member and so does class C. Now, class D inherits two members with the
 * same name.
*/
class D: public B, public C{
public:
    int getID() {return ID;}
};

int main(){
    D d;
    std::cout << d.getID() << std::endl;

    return 0;
}
