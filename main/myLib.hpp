#pragma once

#include <cstdint>

template<typename T>
T reverseNumber(T a)
{
    T ret = 0;
    for(int i = 0; i < sizeof(T); i++) {
        uint8_t sw = ((uint8_t*)&a)[i];
        uint8_t h = ((sw & 0xf) << 4);
        uint8_t l = ((sw & 0xf0) >> 4);
        ((uint8_t*)&ret)[sizeof(T) - 1 - i] = (h | l);
    }
    return ret;
}

uint32_t keygenAlgo(uint16_t* a1);
