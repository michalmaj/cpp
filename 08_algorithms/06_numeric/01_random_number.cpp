/*
 * C++ inherites the numeric function from C and has a random number library.
 * Random numbers are necessary for many domains, e.g., to test software, to generate cryptographic keys or
 * for computer games. The random number facility of C++ consists of two componenets. There is the 
 * generation of the random numbers, and there is the distribution of these numbers. Both components need 
 * the header <random>.
 * The random number generator generates a random number stream between a minimum and maximum value. This 
 * stream is initialized by a "so-called" seed, guaranteeing different sequences of random numbers.
 * A random number generator of type Generator supports four different requests:
 *  Generator::result_type: data type of the generated random number.
 *  gen(): returns a random nuber.
 *  gen.min(): returns the minimum random number that can be returned by gen().
 *  gen.max(): returns the maximum random number that can be returned by gen().
 * The random number library supports several random number generators. The best known are the Mersenne
 * Twister, the std::default_random_engine that is chosen by the implementation and std::random_device.
 * std::random_device is the only true random number generator, but not all platforms offer it.
 * The random number distribution maps the random number with the help of the random number generator gen
 * to the selected distribution.
*/
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <random>
 
static const int NUM=1000000;

void writeToFile(const char* fileName, const std::map<int, int>& data){
    std::ofstream file(fileName);
    
    if(!file){
        std::cerr << "Could not open the file " << fileName << ".\n";
        exit(EXIT_FAILURE);
    }
    
    // print the datapoints to the file
    for(const auto& [key, value] : data)
        std::cout << key << " " << value << std::endl;
    std::cout << "-------------------------------------------------------------\n";
}

int main(){
    std::random_device seed;
    
    // default generator
    std::mt19937 engine(seed());
    
    // distribution
    
    // min = 0, max = 20
    std::uniform_int_distribution<> uniformDist(0, 20);
    
    // mean = 50, sigma = 8
    std::normal_distribution<> normDist(0, 20);
    
    // mean = 6
    std::poisson_distribution<> poiDist(6);
    
    // alpha = 1
    std::gamma_distribution<> gammaDist;
    
    std::map<int, int> uniformFrequency;
    std::map<int, int> normFrequency;
    std::map<int, int> poiFrequency;
    std::map<int, int> gammaFrequency;

    for ( int i=1; i<= NUM; ++i){
        ++uniformFrequency[uniformDist(engine)];
        ++normFrequency[round(normDist(engine))];
        ++poiFrequency[poiDist(engine)];
        ++gammaFrequency[round(gammaDist(engine))];
    }

    writeToFile("uniform_int_distribution.txt", uniformFrequency);
    writeToFile("normal_distribution.txt", normFrequency);
    writeToFile("poisson_distribution.txt", poiFrequency);
    writeToFile("gamma_distribution.txt", gammaFrequency);

    return 0;
}
