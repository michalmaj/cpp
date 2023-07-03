/*
 * Flags represent the state of the stream stream. The methods for dealing with theses flags need the 
 * header <iostream>. Flags representing the state of a stream are:
 *  Flags                     Query of the flag               Description
 *  std::ios::godbit          stream.good()                   No bit set.
 *  std::ios::eofbit          stream.eof()                    end-of-file bit set.
 *  std::ios::failbit         stream.fail()                   Error.
 *  std::ios::badbit          stream.bad()                    Undefined behaviour.
 *
 * State of a stream
 * Here are examples of conditions causing the different states of a stream:
 *  std::ios::eofbit:
 *    - Reading beyond the last valid character.
 *  std::ios::badbit:
 *    - False formatted reading.
 *    - Reading beyond the last valid character.
 *    - Opening of a file went wrong.
 *  std::ios::badbit:
 *    - Size of the stream buffer cannot be adjusted.
 *    - Code conversion of the stream buffer went wrong.
 *    - A part of the stream threw an exception.
 *  stream.fail():
 *    - Returns whether std::ios::failbit ot std::badbit is set.
 * The state of a stream can be read and set:
 *  stream.clear():
 *    - Initializes the flags and sets the stream in the goodbit state.
 *  stream.clear(sta):
 *    - Initializes the flag and set the stream into sta state.
 *  stream.rdstate():
 *    - Returns the current state.
 *  stream.setstate(fla):
 *    - Sets the additional flag fla.
 *
 * Note: operations on a stream only work if the stream is in the goodbit state. If the stream is in the
 * badbit state we cannot set it to goodbit state.
*/
#include <ios>
#include <iostream>

int main(){
  std::cout << std::boolalpha;

  std::cout << "In failbit-state: " << std::cin.fail() << std::endl;

  std::cout << std::endl;

  int myInt;
  while(std::cin >> myInt){
    std::cout << "Output: " << myInt << std::endl;
    std::cout << "In failbit-state: " << std::cin.fail() << std::endl;
    std::cout << std::endl;
  }

  std::cout << "In failbit-state: " << std::cin.fail() << std::endl;
  std::cin.clear();
  std::cout << "In failbit-state: " << std::cin.fail() << std::endl;


  return 0;
}
