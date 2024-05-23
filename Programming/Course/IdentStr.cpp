#include "IdentStr.h"
#include <iostream>
#include <cstring>

using namespace std;

IdentStr::IdentStr(int val) : Stroka(val) {
    cout << "IdentStr::IdentStr(int val):Stroka(val" << val << ")" << endl;
}

IdentStr::IdentStr(char ch) : Stroka(ch) {
    if (!(pch[0] >= 'a' && pch[0] <= 'z' || pch[0] >= 'A' && pch[0] <= 'Z')) {
        cout << "Bad Symbol, pch[0]=" << pch[0] << endl;
        if (pch)
            delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\x00';
        return;
    }
    cout << "IdentStr::IdentStr(char ch):Stroka(ch)" << endl;
}

IdentStr::IdentStr(const char* str) : Stroka(str) {
    if (!(pch[0] >= 'a' && pch[0] <= 'z' || pch[0] >= 'A' && pch[0] <= 'Z' || pch[0] == '_')) {
        cout << "Bad Symbol, pch[0]=" << pch[0] << endl;
        if (pch)
            delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\x00';
        return;
    }
    for (int i = 1; i < len; i++) {
        if (!(pch[i] >= 'a' && pch[i] <= 'z' || pch[i] >= 'A' && pch[i] <= 'Z' || pch[i] == '_' || pch[i] >= '0' && pch[i] <= '9')) {
            cout << "Bad Symbol, pch[" << i << "]=" << pch[i] << endl;
            if (pch)
                delete[] pch;
            len = 0;
            pch = new char[len + 1];
            pch[0] = '\x00';
            return;
        }
    }
    const char* keyword[] = {
        "alignas", "alignof", "and", "and_eq", "asm", "atomic_cancel", "atomic_commit",
        "atomic_noexcept", "auto", "bitand", "bitor", "bool", "break", "case", "catch",
        "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", "const",
        "consteval", "constexpr", "constinit", "const_cast", "continue", "co_await",
        "co_return", "co_yield", "decltype", "default", "delete", "do", "double",
        "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float",
        "for", "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace",
        "new", "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private",
        "protected", "public", "reflexpr", "register", "reinterpret_cast", "requires",
        "return", "short", "signed", "sizeof", "static", "static_assert", "static_cast",
        "struct", "switch", "synchronized", "template", "this", "thread_local", "throw",
        "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
        "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
    };
    for (int i = 0; i < 97; i++) {
        if (strcmp(pch, keyword[i]) == 0) {
            cout << "Bad string" << endl;
            if (pch)
                delete[] pch;
            len = 0;
            pch = new char[len + 1];
            pch[0] = '\x00';
            return;
        }
    }
    cout << "IdentStr::IdentStr(const char* str):Stroka(str)" << endl;
}

IdentStr::IdentStr(const IdentStr& from) : Stroka(from) {
    cout << "IdentStr::IdentStr(const IdentStr& from):Stroka(from)" << endl;
}

IdentStr& IdentStr::operator=(const IdentStr& s) {
    if (&s != this) {
        delete[] pch;
        len = strlen(s.pch);
        pch = new char[len + 1];
        strcpy(pch, s.pch);
    }
    cout << "IdentStr& IdentStr::operator=(const IdentStr& s)" << endl;
    return *this;
}

char& IdentStr::operator[](int index) {
    if (index >= 0 && index < len) {
        cout << "char& IdentStr::operator[](int index)" << endl;
        return pch[index];
    }
    return pch[0];
}

IdentStr IdentStr::operator~() {
    char tmp;
    for (int i = 0; i < len / 2; i++) {
        tmp = pch[i];
        pch[i] = pch[len - i - 1];
        pch[len - i - 1] = tmp;
    }

    if (!(pch[0] >= 'a' && pch[0] <= 'z' || pch[0] >= 'A' && pch[0] <= 'Z' || pch[0] == '_')) {
        cout << "Bad Symbol, pch[0]=" << pch[0] << endl;
        if (pch)
            delete[] pch;
        len = 0;
        pch = new char[len + 1];
        pch[0] = '\x00';
    }
    cout << "IdentStr IdentStr::operator~()" << endl;
    return *this;
}

IdentStr::~IdentStr() {
    cout << "IdentStr::~IdentStr()" << endl;
}

bool operator==(const IdentStr& pobj1, const IdentStr& pobj2){
    return !(strcmp(pobj1.pch, pobj2.pch));
}

int IdentStr::find(char c){
    for(int i=0; i<len; i++){
        if(pch[i]==c){
            return i;
        }
    }
    return -1;
}