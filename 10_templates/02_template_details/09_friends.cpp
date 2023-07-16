/*
 * Friends of a class template have access to all members of the class template.
 * A class or a class template can have a friendship to class or class templates, function or function 
 * templates, and types.
 * Rules:
 *  1. The declaration rights in the class have no influence.
 *  2. The access rights in the class have no influence.
 *  3. Friends will not be inherited.
 *  4. Friendship in not transtive.
 * Note: a friend has unrestricted access to the memebrs of the class.
 *
 * General Friends:
 * A class or a template class can grant friendship to each instance of a class template or a function 
 * template.
 *  template <typename T> int myFirendFucntion(T);
 *
 *  template <typename T> class MyFreind;
 *
 *  template <typename T>
 *  class GrantingFriendShipAsClassTemplate{
 *    template <typename U> friend int myFirendFucntion(U);
 *    template <typename U> friend class MyFreind;
 *  };
 * Note: when a class template grants friendship to a template, the typename of the class template 
 * should be different from the typename of the template. If both use the same name, the friendship is 
 * only granted for the same types.
 *
 * Special Freinds:
 * A special freidship is a friendship that depends on the type of the template parameter.
 *  template <typename T> int myFirendFucntion(T);
 *  template <typename T class MyFriend;
 *
 *  template <typename T>
 *  claass GrantingFriendShipAsClassTemplate{
 *    friend int myFirendFucntion<>(double);
 *    friend class MyFriend<int>;
 *    friend class MyFriend<T>;
 *  };
 * If the name of the template parameter is identical to the name of the template parameter granting the 
 * friendship, the friendship will be between instances of the same type.
 *
 * Friend to Types:
 * A class template can grant its friendship to a type parameter.
 *  template <typename T>
 *  class Array{
 *    friend T;
 *    ...
 *  };
 *  Array<Account> myAccount;
*/
#include <iostream>

template <typename T> void myFriendFucntion(T);
template <typename U> class MyFriend;

class GrantingFriendShipAsClass{

  template <typename U> friend void myFriendFucntion(U);
  template <typename U> friend class MyFriend;

private:
  std::string secret{"My secret from GrantingFriendShipAsClass."};
};

template <typename T>
class GrantingFriendShipAsClassTemplate{

  template <typename U> friend void myFriendFucntion(U);
  template <typename U> friend class MyFriend;

private:
  std::string secret{"My secret from GrantingFriendShipAsClassTemplate."};
};

template <typename T>
void myFriendFucntion(T){
  GrantingFriendShipAsClass myFriend;
  std::cout << myFriend.secret << std::endl;

  GrantingFriendShipAsClassTemplate<double> myFriend1;
  std::cout << myFriend1.secret << std::endl;
}

template <typename T>
class MyFriend{
public:
  MyFriend(){
    GrantingFriendShipAsClass myFriend;
    std::cout << myFriend.secret << std::endl;

    GrantingFriendShipAsClassTemplate<T> myFriend1;
    std::cout << myFriend1.secret << std::endl;
  }
};


int main(){

  int a{2023};
  myFriendFucntion(a);

  MyFriend<double> myFriend;

  std::cout << std::endl;



  return 0;
}
