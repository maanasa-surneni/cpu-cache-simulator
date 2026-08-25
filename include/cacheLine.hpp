#pragma once

#include <cstdint>

struct cacheLine {
    bool valid = false; //when valid=false it means that there is currently no meaningful memory block stored here
    std::uint64_t tag = 0; //tag tells us which memory block currently occupies this cache location
};