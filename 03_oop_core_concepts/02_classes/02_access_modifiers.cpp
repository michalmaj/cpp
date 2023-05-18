/*
 * In C++, we can impose access restriction on different data members and member functions. The restrictions
 * are specified through access modifiers. Access modifiers are tags we can associate with each member to
 * define which parts of the program can access it directly.
 *
 * There are three types of access modifiers:
 * 1. Private
 *  A private member cannot be accessed directly from outside the class. The aim to keep it hidden from the
 *  users and other classes. It is a popular practice to keep the data members private since we do not want
 *  anyone manipulating our data directly. By default, all declared members are private in C++. However, we 
 * can also make members private using the private: heading.
 * 2. Public
 *  This tag indicates that the members can be directly accessed by anything which is in the same scope as
 *  the class object. Member functions are usually public as they provide the interface through which the
 *  application can communicate wiyh our private members. Public members must be declared using the public:
 *  heading. Public members of a class can be accessed by a class object using the dot operator.
 * 3. Protected
 *  The protected category is unque. The access level to the protected members lies somewhere between
 *  private and public. The primary use of the protected tag is to implement inheritance, which is the 
 *  process of creating classes out of classes.
*/

#include <iostream>

class Class1{
    int num; // This is, by default, a private data member
public: // Attributes in this list are public
    void setNum(){
        // The private varable is drectly accessible over here!
    }
};

class Class2{
private:
    int num; // We have explicitly defined that the variable is private
};

int main(){
    Class1 c; // Object created.
    c.setNum(); // Can manipulate the value of num.
    //c.num = 20; // This will cause an error since num is private.

    return 0;
}
