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

    std::size_t cacheSize = 512;
    std::size_t lineSize = 64;

    for (int i{2}; i < argc; ++i) {
        std::string argument = argv[i];

        if (argument == "--cache-size" && i+1 < argc) {
            cacheSize = std::stoull(argv[++i]);
        }
        else if (argument == "--line-size" && i+1 < argc) {
            lineSize = std::stoull(argv[++i]);
        }
    }

    if (cacheSize == 0 || lineSize == 0) {
        std::cerr << "Error: cache size and line size must be greater than 0" << std::endl;
        return 1;
    }

    if (cacheSize % lineSize != 0) {
        std::cerr << "Error: cache size must be divisible by line size" << std::endl;
        return 1;
    }

    std::string traceFile = argv[1];

    std::ifstream file(traceFile); //creates an input file stream (an object used to read data from a file)

    if (!file.is_open()) {
        std::cerr << "Error: could not open trace file" << std::endl;
        return 1;
    }

    cache cache(cacheSize, lineSize);

    std::cout << "CPU Cache Simulator" << std::endl;
    std::cout << "Cache size: " << cacheSize << " bytes" << std::endl;
    std::cout << "Line size: " << lineSize << " bytes" << std::endl;

    std::string line;

    while (std::getline(file, line)) { //keep reading the file one line at a time until there are no lines left
        if (line.empty()) {
            continue;
        }
        
        std::istringstream stream(line);

        char operation;
        std::string addressString;

        stream >> operation >> addressString;

        if (stream.fail()) {
            std::cerr << "Warning: invalid trace line: " << line << std::endl;
            continue;
        }

        std::uint64_t address = std::stoull(addressString, nullptr, 16); //std::stoull is string to unsigned long long

        bool hit = cache.access(address);

        std::cout << operation << " " << addressString << " -> " << (hit ? "HIT" : "MISS") << std::endl;
    }

    std::cout << "\nStatistics" << std::endl;
    std::cout << "Accesses: " << cache.getTotalAccesses() << std::endl;
    std::cout << "Hits:     " << cache.getHits() << std::endl;
    std::cout << "Misses:   " << cache.getMisses() << std::endl;
    std::cout << "Hit rate: " << cache.getHitRate() * 100.0 << "%" << std::endl;

    return 0;
}