/*
 * A string can read from an input stream via >> and wrte to an output stream via <<. The global function 
 * getline empowers us to read from an input stream line by line until the end-of-file character.
 * There are four variations of the getline function available,The first two arguments are the input stream
 * is and the string line holding the line read. Optionally we can specify a special line separator. The 
 * function returns reference to the input stream:
 *  istream& getline (istream& is, string& line, char delim);
 *  istream& getline (istream&& is, string& line, char delim);
 *  istream& getline (istream& is, string& line);
 *  istream& getline (istream&& is, string& line);
 *
 * getline consumes the whole line including empty spaces. Only the line separator is ignored. The function  
 * needs the header <string>.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> readFromFile(const char* fileName){
    std::ifstream file(fileName);
    
    if(!file){
        std::cerr << "Could not open the file " << fileName << ".\n";
        exit(EXIT_FAILURE);
    }
    std::vector<std::string> lines;
    std::string line;
    
    while(getline(file, line))
        lines.push_back(line);
        
    return lines;
}

int main(){

    std::string fileName;
    std::cout << "Your filename: ";
    std::cin >> fileName;
    
    auto lines = readFromFile(fileName.c_str());
    for(int num{0}; const auto& line : lines) // -std=c++20
        std::cout << ++num << ": " << line << std::endl;

    return 0;
}
