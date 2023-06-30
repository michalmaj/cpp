/*
 * std::regex_match determines if text matches a text pattern. We can further analyze the search result of
 * type std::match_results.
 */
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main(){
  // Regular expression for a number, not includeing an exponent
  std::string numberRegEx(R"([-+]?([0-9]*\.[0-9]+|[0-9]+))");

  // Reguar expression holder
  std::regex rgx(numberRegEx);

  // Using const char*
  const char* numChar{"2011"};
  if(std::regex_match(numChar, rgx))
    std::cout << numChar << " is a number.\n";

  // Using std::string
  const std::string numStr{"3.14159265359"};
  if (std::regex_match(numStr, rgx)){
    std::cout << numStr << " is a number." << std::endl;
  }

  // Using bidirectional iterators
  const std::vector<char> numVec{{'-', '2', '.', '7', '1', '8', '2', '8', '1', '8', '2', '8'}};
  if(std::regex_match(numVec.begin(), numVec.end(), rgx)){
    for(const auto& c : numVec)
      std::cout << c;
    std::cout << " is a number\n";
  }

  return 0;
}
