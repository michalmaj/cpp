/*
 * File streams enable us to work with files. They need the header <fstream>. The file streams 
 * automatically manage the lifetime of their life.
 * Whether we use a file stream for input or output or with the character type char or wchar_t there are
 * various file stream classes:
 *  Class:                        Use:
 *  ifstream and wifstream        File stream for the input of data of char and wchar_t.
 *  ofstream and wofstream        File stream for the output of data of char and wchar_t.
 *  fstream and wifstream         File stream of the input and output of data of char and wchar_t.
 *  filebuf and wfilebu           Data buffer of type char and wchar_t.
 *
 * Set the file position pointer: file streams used for reading and writing have to set the file position
 * after the contents change.
 *
 * Flags enable us to set the opening mode of a file stream. Here are a few of those flags:
 *  Flag                Description
 *  std::ios::in        Opens the file stream for reading.
 *  std::ios::out       Opens the file stream for writing.
 *  std::ios::app       Appends the character to the end of the stream.
 *  std::ios::ate       Sets the initial position of the file position pointer on the end of the file.
 *  std::ios::trunc     Deletes the original file.
 *  std::ios::binary    Suppresses the interpretation of an escape sequence in the file stream.
 *
 * Opening of a file with C++:
 * The file has to exist with the mode "r" and "r+". On the contrary, the file is to be created with "a"
 * and "w+". The fle is overwritten with "w".
 *
 * We can explicitly manage the lifetime of a file stream:
 *  Flag                                Description
 *  infile.open(name)                   Opens the file name for reading.
 *  infile.open(name, flags)            Open the file name with flags flags fore reading.
 *  infile.close()                      Close the fle name.
 *  infle_is_open()                     Checks if the file is open.
 *
 * Random Access:
 * Random access enables us to set the fle position pointer arbitrarily.
 * When a file stream is constructed, the files position pointer to the beginning of the file. We can 
 * ajdust the position with the methods of the file stream file.
 * Here are the methods for navigating in a file stream:
 *  Method                        Description
 *  file.tellg()                  Returns the read position of file.
 *  file.tellp()                  Returns the write position of file.
 *  file.seekg(pos)               Sets the read position of file to pos.
 *  file.seekp(pos)               Sets the write positon of file to pos.
 *  file.seekg(off, rpos)         Sets the read position of file to the offset off relative to rpos.
 *  file.seekp(off, rpos)         Sets the write position of file to the offset off relative to rpos.
 *
 * Navigate in a file stream:
 * off has to be a nuber. rpos can have three values:
 *  rpos value                    Description
 *  std::ios::beg                 Position at the beginning of the file.
 *  std::ios::cur                 Position at the current position.
 *  std::iost::end                Position at the end of the file.
 *
 * Note: if we randomly access a file, the C++ runtime does not check the file boundaries. Reading or 
 * writing data outside the boundaries is undefined behaviour.
*/
#include <fstream>
#include <iostream>
#include <string>

void writeFile(const std::string& name){
  std::ofstream outFile(name);

  if(!outFile){
    std::cerr << "Could not open file " << name << std::endl;
    exit(1);
  }

  for(unsigned int i{0}; i < 10; ++i)
    outFile << i << "        0123456789" << std::endl;
}

int main(){
  
  std::string random{"random.txt"};

  writeFile(random);

  std::ifstream inFile(random);

  if(!inFile){
    std::cerr << "Could not open file " << random << std::endl;
    exit(1);
  }

  std::string line;

  std::cout << "The whole file:\n";
  std::cout << inFile.rdbuf();
  std::cout << "inFile.tellg(): " << inFile.tellg() << std::endl;

  std::cout << std::endl;

  inFile.seekg(0);
  inFile.seekg(0, std::ios::beg); // redundant
  std::getline(inFile, line);
  std::cout << "line contains: " << line << std::endl;

  inFile.seekg(20, std::ios::cur);
  std::getline(inFile, line);
  std::cout << "line contains: " << line << std::endl;

  inFile.seekg(-20, std::ios::end);
  std::getline(inFile, line);
  std::cout << "line contains: " << line << std::endl;



  return 0;
}
