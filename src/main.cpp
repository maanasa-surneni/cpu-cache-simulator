#include <iostream>

#include "cache.hpp"

int main() {
    cache cache(512, 64);

    std::cout << "CPU Cache Simulator" << std::endl;

    std::cout << "0x2000 -> " << (cache.access(0x2000) ? "HIT" : "MISS") << std::endl;
    std::cout << "0x2004 -> " << (cache.access(0x2004) ? "HIT" : "MISS") << std::endl;
    std::cout << "0x2040 -> " << (cache.access(0x2040) ? "HIT" : "MISS") << std::endl;
    std::cout << "0x2200 -> " << (cache.access(0x2200) ? "HIT" : "MISS") << std::endl;
    std::cout << "0x2000 -> " << (cache.access(0x2000) ? "HIT" : "MISS") << std::endl;
    
    return 0;
}