/*
 * If we overload the input and output operators, our data type behaves like a bult-in data type.
 * Example for Fraction class:
 *  friend std::istream& operator>> (std::istream& in, Fraction& frac);
 *  friend std::ostream& operator<< (std::ostream& out, const Fraction& frac);
 *
 * For overloading the nput and output operators we have to keep a few rules in mind:
 *  - To support the chaining of input and output operations we have to get and return the input and
 *    output stream by non-constant reference.
 *  - To access the private memebrs of the class, the input and output operators have to be friends of
 *    our data type.
 *  - The input operator >> takes its data type as a non-constant reference.
 *  - The output operator << takes its data type as a constant reference.
*/
#include <iostream>

class Fraction{
  friend std::istream& operator>> (std::istream& in, Fraction& frac);
  friend std::ostream& operator<< (std::ostream& out, const Fraction& frac);

public:
  Fraction(int num=0, int denom=1): numerator(num), denominator(denom) {}

private:
  int numerator;
  int denominator;
};

  std::istream& operator>> (std::istream& in, Fraction& frac){
    in >> frac.numerator;
    in >> frac.denominator;
    return in;
  }

  std::ostream& operator<< (std::ostream& out, const Fraction& frac){
    out << frac.numerator << "/" << frac.denominator;
    return out;
  }
int main(){
  std::cout << std::endl;
 
  Fraction frac(3, 4);
  Fraction frac2(7, 8);
  std::cout << "frac(3, 4): " <<  frac << std::endl;
  std::cout << frac << "   " << frac2 << std::endl;
 
  std::cout << std::endl;
 
  std::cout << "Enter two natural numbers for a Fraction: " << std::endl;
  Fraction fracDef;
  std::cin >> fracDef;
  std::cout << "fracDef: " << fracDef << std::endl;
 
  std::cout << std::endl;

  return 0;
} 
