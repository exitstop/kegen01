#include "myLib.hpp"
#include "data.h"

#include <iostream>
#include <cstdint>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc!=3) {
        cout << "example: ./main firstname lastname" << endl;
        return 0;
    }

    cout << hex << endl;
    // Размер нашего украденного массива данных
    constexpr int SizeData = sizeof(data);
    std::array<uint8_t, SizeData> a1{0};
    // Скопируем сырой массив в array
    ::memcpy(a1.data(), data, SizeData);

    char * ptrFirstName = &((char*)a1.data())[0x1d28];
    char * ptrLastName = &((char*)a1.data())[0x1d38];

    uint32_t *magicNumber = (uint32_t*)&(((char*)a1.data())[0x1d54]);
    uint32_t *serialNumber = (uint32_t*)&(((char*)a1.data())[0x1d48]);

    string firstName(strlen(argv[1])+1, ' ');
    string lastName(strlen(argv[2])+1, ' ');
    // Запишем в строку наши аргументы включая символ \0
    ::memcpy(&firstName[0], argv[1], firstName.size());
    ::memcpy(&lastName[0], argv[2], lastName.size());

    // Копируем "first name" и "last name" в украденный массив из crackme2
    ::memcpy(ptrFirstName, &firstName[0], firstName.size());
    ::memcpy(ptrLastName, &lastName[0], lastName.size());

    // Запустим декомпилированный кусок кода из crackme2
    int ret = keygenAlgo((uint16_t*)a1.data());

    cout << "[keygen for crackme2]" << endl;
    cout << endl;
    if( ret == 0 ) {
        // Выведем регистрационные данные для crackme2
        cout << "FirstName:    " << firstName << endl;
        cout << "LastName:     " << lastName << endl;
        cout << "SerialNumber: " << reverseNumber<uint32_t>(0x100010000 - *magicNumber) << endl;
    } else {
        cout << "error = " << ret << endl;
    }

    return 0;
}
