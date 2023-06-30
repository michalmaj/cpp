/*
 * std::regex_replace replaces sequences in a text matching a text pattern. It returns in the simple form
 * std::regex_replace(text, regex, replString) its resut as strng. The function replaces an occurence of
 * regex in text with replString.
 */
#include <iomanip>
#include <iostream>
#include <regex>
#include <string>

int main(){
  std::string future{"Future"};
  size_t len = future.size();

  std::string unofficialStandardName{"The unofficial name of the new C++ standard is C++0x."};
  std::cout << std::setw(len) << std::left << "Past: " << unofficialStandardName << std::endl;

  // Replace C++0x with C++11
  std::regex rgxCpp{R"(C\+\+0x)"};
  std::string newCppName{"C++11"};

  std::string newStandardName{std::regex_replace(unofficialStandardName, rgxCpp, newCppName)};

  // Replace unofficial with official
  std::regex rgxOff{"unofficial"};
  std::string makeOfficial{"official"};
 
  std::string officialName{std::regex_replace(newStandardName, rgxOff, makeOfficial)};
  std::cout << std::setw(len) << std::left  << "Now: " << officialName << std::endl;

  return 0;
}
