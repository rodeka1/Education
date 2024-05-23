#include "BitStr.h"
#include <iostream>
#include <cstring>

char* sumBitStrings(const char* str1, const char* str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int maxLength = (len1 > len2) ? len1 : len2;

    char* result = (char*)malloc((maxLength + 1) * sizeof(char));
    result[maxLength] = '\0';

    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = maxLength - 1;

    while (k >= 0) {
        int sum = carry;
        if (i >= 0)
            sum += str1[i] - '0';
        if (j >= 0)
            sum += str2[j] - '0';
        carry = sum / 2;
        result[k] = (sum % 2) + '0';
        i--;
        j--;
        k--;
    }

    if (carry) {
        char* newResult = (char*)malloc((maxLength + 2) * sizeof(char));
        newResult[0] = '1';
        memcpy(newResult + 1, result, maxLength * sizeof(char));
        newResult[maxLength + 1] = '\0';
        free(result);
        result = newResult;
    }

    return result;
}

BitStr::BitStr(int val) : Stroka(val) {}

BitStr::BitStr(const char* str) : Stroka(str) {
    if(!(pch[0]=='0' || pch[0]=='1')){
        std::cout << "Bad symbol, pch[0]=" << pch[0] << std::endl;
        if (pch)
            delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\x00';
        return;
    }
    std::cout << "BitStr::BitStr(const char* str) : Stroka(str)" << std::endl;
}

BitStr::BitStr(const BitStr& from) : Stroka(from) {
    std::cout << "BitStr::BitStr(const BitStr& from) : Stroka(from)" << std::endl;
}

BitStr::~BitStr() {
    std::cout << "BitStr::~BitStr()" << std::endl;
}

BitStr& BitStr::operator=(const BitStr& BS) {
    if (&BS != this) {
        delete[] pch;
        len = std::strlen(BS.pch);
        pch = new char[len + 1];
        std::strcpy(pch, BS.pch);
    }
    std::cout << "BitStr& BitStr::operator=(const BitStr& BS)" << std::endl; 
    return *this;
}

BitStr operator+(const BitStr& pobj1, const BitStr& pobj2) {
    int carry;
    BitStr tmp = BitStr(pobj1);
    char* pchtmp;
    if(pobj1.len >= pobj2.len)
        pchtmp = new char[pobj1.len+2];
    else
        pchtmp = new char[pobj2.len+2];

    pchtmp = sumBitStrings(pobj1.pch, pobj2.pch);
    if (tmp.pch)
        delete[] tmp.pch;
    tmp.pch = pchtmp;
    tmp.len = std::strlen(tmp.pch);
    std::cout << "BitStr operator+(const BitStr& pobj1, const BitStr& pobj2)" << std::endl;
    return tmp;
}

bool operator==(const BitStr& pobj1, const BitStr& pobj2){
    std::cout << "bool operator==(const BitStr& pobj1, const BitStr& pobj2)" << std::endl;
    return !(strcmp(pobj1.pch, pobj2.pch));
}


void BitStr::Invert() {
    for (int i = 0; i < len; i++) {
        pch[i] = (pch[i] == '0') ? '1' : '0';
    }
    std::cout << "void BitStr::Invert()" << std::endl;
    return;
}