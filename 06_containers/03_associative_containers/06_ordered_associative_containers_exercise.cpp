/*
 * The program how frequently a word is used in a text. This is a typical use-case for an ordered 
 * associative contaner.
*/
#include <regex>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>

using str2Int = std::unordered_map<std::string, size_t>;
using intAndWords = std::pair<size_t, std::vector<std::string>>;
using int2Words = std::map<size_t, std::vector<std::string>>;

// Count the frequence of each word
str2Int wordCount(const std::string& text){
    std::regex wordReg(R"(\w+)");
    std::sregex_iterator wordItBegin(text.begin(), text.end(), wordReg);
    const std::sregex_iterator wordItEnd;
    str2Int allWords;
    
    while(wordItBegin != wordItEnd){
        ++allWords[wordItBegin->str()];
        ++wordItBegin;
    }
    
    return allWords;
}

// Get to all frequencies the appropriate words
int2Words frequencyOfWords(str2Int& wordCount){
    int2Words freq2Words;
    for(auto wordIt : wordCount){
        auto freqWord = wordIt.second;
        
        if(freq2Words.find(freqWord) == freq2Words.end())
            freq2Words.insert(intAndWords(freqWord, {wordIt.first}));
        else
            freq2Words[freqWord].push_back(wordIt.first);
    }
    
    return freq2Words;
}

int main(){
    std::cout << std::endl;
    
    //Get the filename
    std::string myFile = "Test.rtf";
    
    // Open the file
    std::ifstream file(myFile, std::ios::in);
    if(!file){
        std::cerr << "Can't open file " + myFile + "!\n";
        exit(EXIT_FAILURE);
    }
    
    // Read the file
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string text(buffer.str());
    
    // Get the frequence of each word
    auto allWords = wordCount(text);
    
    std::cout << "The first 20 (key, value)-pairs:\n";
    auto end = allWords.begin();
    std::advance(end, 20);
    for(auto pair = allWords.begin(); pair != end; ++pair)
        std::cout << "(" << pair->first << ": " << pair->second << ")\n";
    std::cout << std::endl << std::endl;
    
    std::cout << "allWords[Web]: " << allWords["Web"] << std::endl;
    std::cout << "allWords[The]: " << allWords["The"] << std::endl; 
    std::cout << std::endl;
    
    std::cout << "Number of unique words: " << allWords.size() << std::endl;
    std::cout << std::endl;
    
    size_t sumWords = 0;
    for(auto wordIt : allWords)
        sumWords += wordIt.second;
    std::cout << "Total number of words: " << sumWords << std::endl;
    std::cout << std::endl;
    
    auto allFreq = frequencyOfWords(allWords);
    std::cout << "Number of different frequencies: " << allFreq.size() << std::endl;
    std::cout << std::endl;
    
    std::cout << "All frequencies: ";
    for(auto freqIt : allFreq)
        std::cout << freqIt.first << " ";
    std::cout << std::endl << std::endl;
    
    std::cout << "The most frequently occuring word(s): ";
    auto atTheEnd = allFreq.rbegin();
    std::cout << atTheEnd->first << " times occures: ";
    for(auto word : atTheEnd->second)
        std::cout << word << " ";
    std::cout << std::endl << std::endl;
    
    std::cout << "All word which appears more then 1000 times:" << std::endl;
    auto biggerIt= std::find_if(allFreq.begin(), allFreq.end(),
                              [](intAndWords iAndW){return iAndW.first > 1000;});
    if (biggerIt == allFreq.end()){
    std::cerr << "No word appears more then 1000 times !" << std::endl;
    exit(EXIT_FAILURE);
    }
    else{
    for (auto allFreqIt= biggerIt; allFreqIt != allFreq.end(); ++allFreqIt){
      std::cout << allFreqIt->first << " :";
      for (auto word: allFreqIt->second) std::cout << word << " ";
      std::cout << std::endl;
    }
    }
  std::cout << std::endl;

    return 0;
}
