#include "myLib.hpp"

// декомпилированный код из crackme2
uint32_t keygenAlgo(uint16_t* a1)
{
    uint16_t v2;
    int8_t* v3;
    uint32_t ecx4;
    uint32_t ecx5;
    int8_t* v6;
    uint32_t ecx7;
    uint32_t ecx8;
    uint32_t ecx9;
    uint32_t ecx10;
    uint32_t ecx11;
    uint32_t eax12;

    v2 = 0;
    while (1) {
        v3 = (int8_t*)((int32_t)a1 + ((int32_t)static_cast<uint32_t>(*(uint16_t*)((int32_t)a1 + (static_cast<uint32_t>(v2) << 3))) >> 3));
        ecx4 = static_cast<uint32_t>(*(uint16_t*)((int32_t)a1 + (static_cast<uint32_t>(v2) << 3))) & 7;
        ecx5 = (uint32_t)static_cast<int32_t>(*v3) & 1 << *(uint8_t*)&ecx4;
        v6 = (int8_t*)((int32_t)a1 + ((int32_t)static_cast<uint32_t>(*(uint16_t*)((int32_t)a1 + (static_cast<uint32_t>(v2) << 3) + 2)) >> 3));
        if (!*(int8_t*)&ecx5) {
            ecx7 = static_cast<uint32_t>(*(uint16_t*)((int32_t)a1 + (static_cast<uint32_t>(v2) << 3) + 2)) & 7;
            ecx8 = (uint32_t)static_cast<int32_t>(*v6) & (1 << *(uint8_t*)&ecx7 ^ 0xffffffff);
            *v6 = *(int8_t*)&ecx8;
        } else {
            ecx9 = static_cast<uint32_t>(*(uint16_t*)((int32_t)a1 + (static_cast<uint32_t>(v2) << 3) + 2)) & 7;
            ecx10 = (uint32_t)static_cast<int32_t>(*v6) | 1 << *(uint8_t*)&ecx9;
            *v6 = *(int8_t*)&ecx10;
        }
        ecx11 = v2 + (*(uint16_t*)((int32_t)a1 + (static_cast<uint32_t>(v2) << 3) + 4) + 1);
        v2 = *(uint16_t*)&ecx11;
        if (static_cast<uint32_t>(v2) == 0xffff) 
            break;
        eax12 = static_cast<uint32_t>(v2);
        if (eax12 > 0x601) 
            goto addr_0x401174_7;
    }
    eax12 = 0;
addr_0x40117b_10:
    return eax12;
addr_0x401174_7:
    goto addr_0x40117b_10;
}
