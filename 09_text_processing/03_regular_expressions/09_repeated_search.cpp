/*
 * It's quite convenient to iterate with std::regex_iterator and std::regex_token_iterator over the
 * matched texts. std::regex_iterator supports the matches and their capture groups. 
 * std::regex_token_iterator supports more. We can address the components of each capture and by using a
 * negative index, we can access the text between the matches.
 */
#include <iostream>
#include <unordered_map>
#include <regex>

int main(){
  
  std::string text{"That's a (to me) amazingly frequent question. It may be the most frequently asked question. Surprisingly, C++0x feels like a new language: The pieces just fit together better than they used to and I find a higher-level style of programming more natural than before and as efficient as ever."};

  //Regular expression for a word
  // A word consists of at least one character (\w+).
  std::regex wordReg(R"(\w+)");

  // Get all words from text
  // Above regular expression is used to define the begin iterator wordItBegin and the end iterator
  // wordItEnd.
  std::sregex_iterator wordItBegin(text.begin(), text.end(), wordReg);
  const std::sregex_iterator wordItEnd;

  // Use unordered_map
  std::unordered_map<std::string, size_t> allWords;

  // count the words
  // The iteration through the matches happens in the for loop. Each word increments the counter:
  // ++allWords[wordItBegin]->str(). A word with counter equals 1 is created if it is not already
  // in allWords map.
  for (; wordItBegin != wordItEnd;++wordItBegin){
    ++allWords[wordItBegin->str()];
  }
 
  for ( auto wordIt: allWords) std::cout << wordIt.first << ": " << wordIt.second << "\n" ;

  return 0;
}
