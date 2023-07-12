/*
 * Template specialization addresses the need to have different code for different template argument
 * types. Templates define the behavior of families of classes and functions:
 *  - Often it is necessary that special types, non-typesm or template as arguments are treated as 
 *    special.
 *  - We can fully specalize templates, class templates can even be partially specialized.
 *  - The methods and attributes of specialization don't have to be identical.
 *  - General or Primary templates can coexist with partially or fully specalized templates.
 * Note: the compiler prefers fully specialized to partially specialized templates and partially 
 * specialized templates to primary templates.
 *
 * Primary Template:
 * The primary template has to be declared before the partially or fully specialized templates.
 * Note: If the primary template is not needed, just a declaration will suffice.
 *  template <typename T, int Line, int Column> class Matrix; // Primary Template.
 *
 *  template <typename T> // Partial Specialization.
 *  class Matrix<T, 3, 3>{}; 
 *
 *  template <> class Matrix<int, 3, 3>{}; // Fully Specialization.
 *
 * Partial Specialization:
 * The partial specialization of a template is only supported for class templates and it has template 
 * arguments and template parameters.
 *  template <typename T, int Line, int Column> class Matrix{};
 *
 *  template <typename T>
 *  class Matrix<T, 3, 3> {};
 *
 *  template <int Line, int Column>
 *  class Matrix<double, Line, Column>{};
 *
 *  Matrix<int, 3, 3> m1 // class Matrix<T, 3, 3>
 *  Matrix<double, 10, 10> m2 // class Matrix <double, Line, Column>
 *  Matrix<std::string, 4, 3> m3 // class Matrix<T, Line, Column>
 * Rules for Partial Specialization:
 *  1. The compiler uses a partial specialization if the parameters of the class are a subset of the 
 *     template arguments.
 *  2. The template parameters which are not specified must be given as template arguments, for example,
 *     template <typename T> class Matrix<T, 3, 3>{};
 *  3. The number and sequence of the template arguments must match with the number and sequence of the 
 *     template parameters of the primary template.
 *  4. If we use defaults for template parameters, we don't have to provide the template arguments. Only 
 *     the primary template accepts defaults.
 * Rules for Right Specialization
 * Three rules for getting the right specialization:
 *  1. If the compiler finds only one specialization, it uses that specialization.
 *  2. If the compiler finds more than one specialization, it uses the most specalized one. If the 
 *     compiler can't find the most specalized one, it throws an error.
 *  3. If the compiler finds no specialization, it simply uses the primary template.
 * Note: template A is more specialized than template B if:
 *  - B can accept all arguments that A can accept.
 *  - B can accept arguments that A cannot accept.
 *
 * Fully Specialization
 * For a fully specialized template, we have to provide all template arguments for the template 
 * parameters. The number of template parameters is reduced to an empty list.
 *  template <typename T> struct Type{
 *    std:string getName() const{
 *      return "Unknown";
 *    }
 *  };
 *
 *  template<>
 *  struct Type<Account>{
 *    std::string getName() const{
 *      return "Account";
 *    }
 *  };
 * If we define the methods of aclass template outside of the class, we have to specify the template 
 * arguments in angle brackets after the name of the class. Define the method of a fully specialized 
 * class template outside the class body without the empty template parameter list: template<>.
 *  template <typename T, int Line, int Column>
 *  struct Matrix;
 *
 *  template <>
 *  struct Matrix<int, 3, 3>{
 *    int numberOfElements() const;
 *  };
 *
 *  int Matrix<int, 3, 3>::numberOfElements() const{
 *    return 3 * 3;
 *  }
*/
// Template Specialization
#include <iostream>

class Account{
public:
  explicit Account(double b): balance(b) {}
  double getBalance() const {return balance;}

private:
  double balance;
};

template <typename T, int Line, int Column>
class Matrix{
public:
  std::string getName() const {return "Primary Template";}
};

template <typename T>
class Matrix<T, 3, 3>{
public:
  std::string getName() const {return "Partial Specialization";}
};

template <>
class Matrix<int, 3, 3>{
public:
  std::string getName() const {return "Fully Specialization";}
};

template <typename T>
bool isSmaller(T fir, T sec){
  std::cout << "Inside Primary Template Function: ";
  return fir < sec;
}

template <>
bool isSmaller<Account>(Account fir, Account sec){
  std::cout << "Inside Fully Specialized Function: ";
  return fir.getBalance() < sec.getBalance();
}

int main(){
  std::cout << std::boolalpha << std::endl;

  Matrix<double, 3, 4> primaryM;
  std::cout << "primaryM.getName(): " << primaryM.getName() << std::endl;

  Matrix<double, 3, 3> partialM;
  std::cout << "partialM.getName(): " << partialM.getName() << std::endl;

  Matrix<int, 3, 3> fullM;
  std::cout << "fullM.getName(): " << fullM.getName() << std::endl;

  std::cout << "isSmaller(3,4): "  << isSmaller(3,4) << std::endl;
  std::cout << "isSmaller(Account(100.0),Account(200.0)): "
    << isSmaller(Account(100.0),Account(200.0)) << std::endl;


  return 0;
}
