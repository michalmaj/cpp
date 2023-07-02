/*
 * The input and output streams enable us to communicate with the outside world. A stream is an infinite
 * character stream on which we can push or pull data. Puch is called writing, pull is called reading.
 * The input and output streams:
 *  - were used long before the first C++ standard (C++98) in 1998,
 *  - are a for the extensibility designed frameword,
 *  - are implemented according to the object-oriented and generic paradigms.
 *
 * Streams
 * A stream is an infinite data stream on which we can push or pull data. String stream and file streams
 * enable strings and files to interact with the stream directly.
 *
 * String Streams
 * String streams need the header <sstream>. Theu are not connected to an input or output stream and 
 * store thier data in a string.
 * Whether we use a string stream for input or output or with the character type char or wchar_t there
 * are various string stream classes:
 *  Class                                     Use 
 *  istringstream and wistringstream          String stream for the input of char or wchar_t.
 *  ostringstream and wostringstream          String stream for the output of char or wchar_t.
 *  stringstream and wstringstream            String stream for the input or output of char or wchar_t.
 *
 * Typical operatons on a string:
 *  - Write data in a string stream:
 *    std::stringstream os;
 *    os << "New String";
 *    os.str(:Another new String);
 *  - Read data from a string stream:
 *    std::stringstream os;
 *    std::string str;
 *    os >> str;
 *    str = os.str;
 *  - Clear a string stream:
 *    std::stringstream os;
 *    os.str("");
*/
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

template <typename T>
T StringTo(const std::string& source){
  std::istringstream iss(source);
  T ret;
  iss >> ret;

  return ret;
}

template <typename T>
std::string ToString(const T& n){
  std::ostringstream tmp;
  tmp << n;
  return tmp.str();
}

int main(){
  std::cout << "5 = "  << std::string("5") << std::endl;
  std::cout << "5 = " <<  StringTo<int>("5") << std::endl;
  std::cout << "5 + 6 = " << StringTo<int>("5") + 6 << std::endl;
   
  std::string erg(ToString(StringTo<int> ("5") + 6 ) ); 
  std::cout << "5 + 6 = " << erg  << std::endl;
   
  std::cout << "5e10: " << std::fixed << StringTo<double>("5e10")  << std::endl;


  return 0;
}
