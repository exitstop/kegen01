#include "myLib.hpp"

// декомпилированный код из crackme2
uint32_t keygenAlgo(uint16_t* a1)
{
    int8_t* tCross;
    int8_t* bt;
    uint16_t counter;
    uint32_t shlCross;
    uint32_t crossRoad;
    uint32_t shlBt;
    uint32_t tm1;
    uint32_t testEnd;

    counter = 0;
    while (1) {
        tCross = (int8_t*)((int32_t)a1 + ((int32_t)(*(uint16_t*)((int32_t)a1 + ((uint32_t)(counter) << 3))) >> 3));
        shlCross = (uint32_t)(*(uint16_t*)((int32_t)a1 + ((uint32_t)(counter) << 3))) & 7;
        crossRoad = (uint32_t)(*tCross) & 1 << *(uint8_t*)&shlCross;
        bt = (int8_t*)((int32_t)a1 + ((int32_t)(uint32_t)(*(uint16_t*)((int32_t)a1 + ((uint32_t)(counter) << 3) + 2)) >> 3));
        if (!*(int8_t*)&crossRoad) {
            shlBt = (uint32_t)(*(uint16_t*)((int32_t)a1 + ((uint32_t)(counter) << 3) + 2)) & 7;
            tm1 = (uint32_t)(int32_t)(*bt) & (1 << *(uint8_t*)&shlBt ^ 0xffffffff);
            *bt = *(int8_t*)&tm1;
        } else {
            shlBt = (uint32_t)(*(uint16_t*)((int32_t)a1 + ((uint32_t)(counter) << 3) + 2)) & 7;
            tm1 = (uint32_t)(int32_t)(*bt) | 1 << *(uint8_t*)&shlBt;
            *bt = *(int8_t*)&tm1;
        }
        testEnd = counter + (*(uint16_t*)((int32_t)a1 + ((uint32_t)(counter) << 3) + 4) + 1);
        counter = *(uint16_t*)&testEnd;
        if ((uint32_t)(counter) == 0xffff) {
            break;
        }
        if (counter > 0x601) {
            return counter;
        }
    }
    return 0;
}
