/*
 * Whenever we verify whether a piece of text satisfies our regular expression, we have to store the 
 * result somewhere, std::match_result allows us to do just that.
 * The object of type std::match_result is the result of a std::regex_match or std::regex_search.
 * std::match_result is a sequentail container having at least one capture group of a std::sub_match
 * object.The std::sub_match objects are sequences of characters.
 *
 * What is a caputr group?
 * Capture groups allow it to further analyse the search result is a regular expression. They are defined
 * by a pair of parenthesses (). The regular expression ((a+)(b+)(c+)) has four capture groups:
 * ((a+)(b+)(c+)), (a+), (b+), (c+). The total result is the 0th capture group.
 *
 * The search result std::smatch smatch has a powerful interface. Some methods of the std::smatch:
 *  Method:                                 Description
 *  smatch.size()                           Returns the number of capture groups.
 *  smatch.empty()                          Returns if the search result has a capture group.
 *  smatch[i]                               Returns the ith capture group.
 *  smatch.length(i)                        Returns the length of the ith capture group.
 *  smatch.position(i)                      Returns the position of the ith capture group.
 *  smatch.str(i)                           Returns the ith capture group as string.
 *  smatch.prefix(), smatch.suffix()        Returns the string before and after the capture group.
 *  smatch.begin(), smatch.end()            Returns the begin and end iterator for the capure groups.
 *  smatch.format(...)                      Formats std::smatch objects for the output.
 */
#include <regex>
#include <iomanip>
#include <iostream>
#include <string>

void showCaptureGroups(const std::string& regEx, const std::string& text){
  // Regular expression holder
  std::regex rgx(regEx);
  
  // Result holder
  std::smatch smatch;

  // Result evaluation
  if(std::regex_search(text, smatch, rgx)){
    std::cout << std::setw(10) << regEx << std::setw(30) << text << std::setw(30) << smatch[0]
      << std::setw(25) << smatch[1] << std::setw(28) << smatch[2] << std::setw(36) << smatch[3] 
      << std::setw(30) << smatch[4] << std::endl;
  }
}

int main(){
 std::cout << std::setw(10) << "reg Expr" << std::setw(30) << "text" << std::setw(30) << "smatch[0]" 
    << std::setw(30) << "smatch[1]" << std::setw(30) << "smatch[2]" << std::setw(30) << "smatch[3]" 
    << std::setw(30) << "smatch[4]" << std::endl; 

  showCaptureGroups("abc+", "abccccc");
 
  showCaptureGroups("(a+)(b+)(c+)", "aaabccc");
 
  showCaptureGroups("((a+)(b+)(c+))", "aaabccc");
 
  showCaptureGroups("(ab)(abc)+", "ababcabc");


  return 0;
}
