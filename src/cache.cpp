#include "cache.hpp"

cache::cache(std::size_t cacheSize, std::size_t lineSize)
    : cacheSize_(cacheSize),
    lineSize_(lineSize),
    numLines_(cacheSize/lineSize),
    lines_(numLines_) // creates some num. of cacheLine objects
    {
}

bool cache::access(std::uint64_t address) {
    totalAccesses_++; 

    std::uint64_t block_num = address / lineSize_;
    std::size_t index = block_num % numLines_;
    std::uint16_t tag = block_num / numLines_;

    cacheLine& line = lines_[index]; //give me a reference to the cache line at this index

    if (line.valid && line.tag == tag) { //HIT only if there is currently valid data there and its tag matches with the requested tag
        hits_++;
        return true;
    }

    misses_++;

    line.valid = true;
    line.tag = tag;

    return false;
}
