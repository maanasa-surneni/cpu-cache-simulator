#include "cache.hpp"

cache::cache(std::size_t cacheSize, std::size_t lineSize)
    : cacheSize_(cacheSize),
    lineSize_(lineSize),
    numLines_(cacheSize/lineSize),
    lines_(numLines_) // creates some num. of cacheLine objects
    {
}