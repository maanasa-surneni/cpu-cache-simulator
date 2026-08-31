#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "cache.hpp"

int main(int argc, char* argv[]) { //lets your program receive command-line arguments
    
    if (argc < 2) {
        std::cerr << "Usage: ./cache-sim <trace-file>" << std::endl;
        return 1;
    }

    std::string traceFile = argv[1];

    std::ifstream file(traceFile); //creates an input file stream (an object used to read data from a file)

    if (!file.is_open()) {
        std::cerr << "Error: could not open trace file" << std::endl;
        return 1;
    }

    cache cache(512, 64);

    std::string line;

    while (std::getline(file, line)) { //keep reading the file one line at a time until there are no lines left
        std::istringstream stream(line);

        char operation;
        std::string addressString;

        stream >> operation >> addressString;

        std::uint64_t address = std::stoull(addressString, nullptr, 16); //std::stoull is string to unsigned long long

        bool hit = cache.access(address);

        std::cout << operation << " " << addressString << " -> " << (hit ? "HIT" : "MISS") << std::endl;
    }

    return 0;
}