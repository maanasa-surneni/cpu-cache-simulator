#include <cassert>
#include <iostream>

#include "cache.hpp"

void testFirstAccessMisses() {
    cache cache(512, 64);

    bool result = cache.access(0x2000);

    assert(result==false);
}

void testRepeatedAccessHits() {
    cache cache(512, 64);

    cache.access(0x2000);
    bool result = cache.access(0x2000);

    assert(result==true);
}

void testSameCacheLineHits() {
    cache cache(512, 64);

    cache.access(0x2000);
    bool result = cache.access(0x2004);

    assert(result==true);
}

void testConflictMiss() {
    cache cache(512, 64);

    cache.access(0x2000);
    cache.access(0x2200);

    bool result = cache.access(0x2000);

    assert(result==false);
}

void testStatistics() {
    cache cache(512, 64);

    cache.access(0x2000); //miss
    cache.access(0x2004); //hit
    cache.access(0x2040); //miss

    assert(cache.getTotalAccesses() == 3);
    assert(cache.getHits() == 1);
    assert(cache.getMisses() == 2);
}

int main() {
    testFirstAccessMisses();
    testRepeatedAccessHits();
    testSameCacheLineHits();
    testConflictMiss();
    testStatistics();

    std::cout << "All cache tests passed!" << std::endl;

    return 0;
}