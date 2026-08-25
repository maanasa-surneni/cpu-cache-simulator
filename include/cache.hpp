#pragma once

#include <cstddef>
#include <vector>

#include "cacheLine.hpp"

class cache {
    public:
        cache(std::size_t cacheSize, std::size_t lineSize); //constructor
    
    private:
        std::size_t cacheSize_; //total cache capacity
        std::size_t lineSize_; //bytes per cache line
        std::size_t numLines_; //num. of cache lines (cacheSize/lineSize)

        std::vector<cacheLine> lines_; //is a dynamically sized array where each entry will contain valid and tag
};