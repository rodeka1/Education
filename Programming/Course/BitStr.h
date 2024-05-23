#ifndef __BITSTR__
#define __BITSTR__

#include "Stroka.h"

class BitStr : public Stroka {
public:
    BitStr(int = 0);
    BitStr(const char*);
    BitStr(const BitStr&);
    ~BitStr();

    BitStr& operator=(const BitStr&);
    friend BitStr operator+(const BitStr&, const BitStr&);
    friend bool operator==(const BitStr&, const BitStr&);

    void Invert();
};

#endif