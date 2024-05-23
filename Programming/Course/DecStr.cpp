#include "DecStr.h"
#include <iostream>
#include <cstring>

DecStr::DecStr(int val) : Stroka(val) {
    std::cout << "DecStr::DecStr(int val):Stroka(val)" << std::endl;
}

DecStr::DecStr(const char* str) : Stroka(str) {
    if (!(pch[0] > '0' && pch[0] <= '9' || pch[0] == '-' || pch[0] == '+')) {
        std::cout << "Bad symbol, pch[0]=" << pch[0] << std::endl;
        if (pch)
            delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\x00';
        return;
    }
    for (int i = 1; i < len; i++) {
        if (!(pch[i] >= '0' && pch[i] <= '9')) {
            std::cout << "Bad stroka, pch[" << i << "]=" << pch[i] << std::endl;
            if (pch)
                delete[] pch;
            len = 0;
            pch = new char[len + 1];
            pch[0] = '\x00';
            return;
        }
    }
    if ((pch[0] == '+' || pch[0] == '-') && pch[1] == '0') {
        std::cout << "Bad symbol pch[1]='0'" << std::endl;
        if (pch)
            delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\x00';
        return;
    }
    std::cout << "DecStr::DecStr(const char* str):Stroka(str)" << std::endl;
}

DecStr::DecStr(const DecStr& from) : Stroka(from) {
    std::cout << "DecStr::DecStr(const DecStr& from):Stroka(from)" << std::endl;
}

DecStr::~DecStr() {
    std::cout << "DecStr::~DecStr()" << std::endl;
}

DecStr& DecStr::operator=(const DecStr& DS) {
    if (&DS != this) {
        delete[] pch;
        len = std::strlen(DS.pch);
        pch = new char[len + 1];
        std::strcpy(pch, DS.pch);
    }
    std::cout << "DecStr& DecStr::operator=(const DecStr& DS)" << std::endl;
    return *this;
}

DecStr operator+(const DecStr& pobj1, const DecStr& pobj2) {
    int num1, num2;
    DecStr tmp = DecStr(pobj1);
    num1 = std::atoi(pobj1.pch);
    num2 = std::atoi(pobj2.pch);
    long long check = (long long)(num1) + (long long)(num2);
    if (check > INT32_MAX || check < INT32_MIN) {
        std::cout << "OUT OF RANGE INT" << std::endl;
        if (tmp.pch)
            delete[] tmp.pch;
        tmp.len = 0;
        tmp.pch = new char[tmp.len + 1];
        tmp.pch[0] = '\x00';
        return tmp;
    }
    char* pchtmp;
    if (pobj1.len >= pobj2.len)
        pchtmp = new char[pobj1.len + 2];
    else
        pchtmp = new char[pobj2.len + 2];
    std::sprintf(pchtmp, "%d", num1 + num2);
    if (tmp.pch)
        delete[] tmp.pch;
    tmp.pch = pchtmp;
    tmp.len = std::strlen(tmp.pch);
    std::cout << "DecStr operator+(const DecStr& pobj1, const DecStr& pobj2)" << std::endl;
    return tmp;
}

DecStr operator-(const DecStr& pobj1, const DecStr& pobj2) {
    int num1, num2;
    DecStr tmp = DecStr(pobj1);
    num1 = std::atoi(pobj1.pch);
    num2 = std::atoi(pobj2.pch);
    long long check = (long long)(num1) - (long long)(num2);
    if (check > INT32_MAX || check < INT32_MIN) {
        std::cout << "OUT OF RANGE INT" << std::endl;
        if (tmp.pch)
            delete[] tmp.pch;
        tmp.len = 0;
        tmp.pch = new char[tmp.len + 1];
        tmp.pch[0] = '\x00';
        return tmp;
    }
    char* pchtmp;
    if (pobj1.len >= pobj2.len) {
        pchtmp = new char[pobj1.len + 2];
        std::sprintf(pchtmp, "%d", num1 - num2);
    } else {
        pchtmp = new char[pobj2.len + 2];
        std::sprintf(pchtmp, "%d", num1 - num2);
    }
    if (tmp.pch)
        delete[] tmp.pch;
    tmp.pch = pchtmp;
    tmp.len = std::strlen(tmp.pch);
    std::cout << "DecStr operator+(const DecStr& pobj1, const DecStr& pobj2)" << std::endl;
    return tmp;
}

bool operator<(const DecStr& pobj1, const DecStr& pobj2) {
    int num1 = std::atoi(pobj1.pch);
    int num2 = std::atoi(pobj2.pch);
    return num1 < num2;
}
