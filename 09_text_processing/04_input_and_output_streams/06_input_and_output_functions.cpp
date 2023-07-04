/*
 * Input:
 * We can read in C++ in two way from the input stream: formatted with the extractor >> and unformatted
 * with explicit method.
 * Output:
 * The extractor operator >>
 *  - is predefined for all built-in types and strings,
 *  - can be implemented for user-defined data types,
 *  - can be configured by format specisiers.
 * Note: std::cn ignores by default leading whitespace.
 *
 * Unformatted Input 
 *  Method                                              Description
 *  is.get(ch)                                          Reads one character into ch.
 *  is.get(buf, num)                                    Reads at mst num characters into the buffer buf.
 *  is.getline(buf, num[, delim])                       Reads at most num characters into the buffer buf.
 *                                                      Uses optionally th line-delimeter delim (eg. \n).
 *  is.gcount()                                         Returns the number of characters that were last
 *                                                      extracted from is by an unformatted operation.
 *  is.ignore(streamsize sz=1, int delim=end-of-file)   Ignores sz characters until delim.
 *  is.peek()                                           Gets one characters from is without consuming it.
 *  is.unget()                                          Pushes the last read character back to is.
 *  is.putback(ch)                                      Pushes the character ch onto the stream is.
 *
 * std::string has a getline function:
 * The getline function os std::strng has a big adventage above the getline function of the istream. The
 * std::string automatically takes care of its memory. On the contrary, we have to reserve the memory
 * for the buffer buf in the is.get(buf, num) function.
*/
#include <iostream>
#include <string>
 
int main(){
 
  std::cout << std::endl;
 
  std::string line;
  std::cout << "Write a line: " << std::endl;
  std::getline(std::cin, line);
  std::cout << line << std::endl;
 
  std::cout << std::endl;
 
  std::cout << "Write numbers, separated by;" << std::endl;
  while ( std::getline(std::cin, line, ';') ) {
    std::cout << line << std::endl;
  }
 
  std::cout << std::endl;
  
  return 0;
}
