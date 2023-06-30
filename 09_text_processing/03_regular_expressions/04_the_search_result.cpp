/*
 * std::sub_match - the capture groups are of type std::sub_match. As with std::match_results C++ defines
 * four synonyms. We can even analyze the capture group:
 *  Method                          Description
 *  cap.matched()                   Indicates if this match was successful.
 *  cap.first(), cap.end()          Returns the begin and end iterator of the character sequence.
 *  cap.length()                    Returns the length of the capture group.
 *  cap.str()                       Returns the capture group as string.
 *  cap.compare(other)              Compares the current capture group with another capture group.
 */
#include <iostream>
#include <string>
#include <regex>

int main(){
  // Simple regular expression matching.
  std::string fnames[]{"foo.txt", "bar.txt", "baz.dat", "zoidberg"};
  std::regex text_regex{R"([a-z]+\.txt)"};

  for(const auto& fname : fnames)
    std::cout << fname << ": " << std::regex_match(fname, text_regex) << std::endl;

  // Extraction of a sub-match
  std::regex base_regex{R"(([a-z]+)\.txt)"};
  std::smatch base_match;

  for (const auto &fname : fnames) {
        if (std::regex_match(fname, base_match, base_regex)) {
            // The first sub_match is the whole string; the next
            // sub_match is the first parenthesized expression.
            if (base_match.size() == 2) {
                std::ssub_match base_sub_match = base_match[1];
                std::string base = base_sub_match.str();
                std::cout << fname << " has a base of " << base << '\n';
            }
        }
    }
 
  // Extraction of several sub-matches
  std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
  std::smatch pieces_match;

  for (const auto &fname : fnames) {
      if (std::regex_match(fname, pieces_match, pieces_regex)) {
          std::cout << fname << '\n';
          for (size_t i = 0; i < pieces_match.size(); ++i) {
              std::ssub_match sub_match = pieces_match[i];
              std::string piece = sub_match.str();
              std::cout << "  submatch " << i << ": " << piece << '\n';
          }   
      }
  }

  return 0;
}
