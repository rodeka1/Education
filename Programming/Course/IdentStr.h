#ifndef __IDENTSTR__
#define __IDENTSTR__

#include "Stroka.h"

class IdentStr : public Stroka {
public:
    IdentStr(int);
    IdentStr(char);
    IdentStr(const char*);
    IdentStr(const IdentStr&);
    ~IdentStr();
    IdentStr& operator=(const IdentStr&);
    char& operator[](int);
    IdentStr operator~();
    friend bool operator==(const IdentStr&, const IdentStr&);
    int find(char);
};

#endif
