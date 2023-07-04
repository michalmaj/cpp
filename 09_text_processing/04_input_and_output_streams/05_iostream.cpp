/*
 * The most frequently used read/write stream is iostream.
 * The stream classes std::istream and std::ostream are often used for the reading and writing of data.
 * Use of std::istream classes requires the <istream> header; use of std::ostream classes requires the
 * <ostream>.
 * C++ has four predefined stream objects for the convenience of dealing with the keyboard and the 
 * monitor:
 *  Stream object       C pendant       Device        Buffered
 *  std::cin            stdin           keyboard      yes
 *  std::cout           stdout          monitor       yes 
 *  std::cerr           stderr          monitor       no
 *  std::clog           stderr          monitor       yes 
 *
 * The small program below uses the stream operators << and >> and the stream manipulator std::endl.
 * The insert operator << pushes characters onto the output stream std::cout; the extract operator >>
 * pulls the characters from the input stream std::cin. We can build chains of insert or extract 
 * operators because both operators return a reference th themselves.
 * std::endl is a stream manipulator because ot puts a '\n' character onto std::cout and flushesh the
 * output buffer.
 * Here are the most frequently used stream manipulators:
 *  Manipulator           Stream type         Description
 *  std::endl             output              Inserts a new-line character and flushes the stream.
 *  std::flush            output              Flushes the stream.
 *  std::ws               input               Discard leading whitespace.
*/
#include <iostream>
 
int main(){
 
  std::cout << std::endl; 
  std::cout << "Type in your numbers(Quit with an arbitrary character): " << std::endl;
   
  int sum{0};
  int val;
 
  while ( std::cin >> val ) sum += val;
 
  std::cout << "Sum: " << sum << std::endl << std::endl;

  return 0; 
}
