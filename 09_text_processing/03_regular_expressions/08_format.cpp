/*
 * std::regex_replace and std::natch_result.format is combination with capture groups ensables us to
 * format text. We can use a format string together with a placehoder to insert the value.
 *
 *  Format escape sequence              Description
 *  $&                                  Returns the total match (0th capture group).
 *  $$                                  Returns $.
 *  $`                                  Returns the text before the total match.
 *  $'                                  Returns the text after the total match.
 *  $i                                  Returns the ith capture group.
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <regex>

int main(){
  std::string future{"Future"};
  size_t len = future.size();

  const std::string unofficial{"unofficial, C++0x"};
  const std::string official{"official, C++11"};

  std::regex regValues{"(.*), (.*)"};

  std::string standardText{"The $1 name of the new C++ standard is $2."};

  // Using std::regex_replace
  // The text matching the first and second capture group of the regular expression regValues is 
  // extracted from the string unofficial. The placehoders $1 and $2 in the text standardText are
  // then replaced by the extracted values.
  std::string textNow = std::regex_replace(unofficial, regValues, standardText);

  std::cout << std::setw(len) << std::left << "Now: " << textNow << std::endl;
  
  // Using std::match_results
  // typede match_results<string::const_iterator> smatch;
  std::smatch smatch;
  if(std::regex_match(official, smatch, regValues)){
    // The strategy of smatch.format(standardText) is similar to std::regex_replace.
    std::string textFuture = smatch.format(standardText);
    std::cout << std::setw(len) << std::left << "Future: " << textFuture << std::endl;
  }

  return 0;
}
