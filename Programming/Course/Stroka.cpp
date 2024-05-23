#include "Stroka.h"
#include <iostream>
#include <cstring>

using namespace std;

Stroka::Stroka(int val):len(val),pch(new char[len+1]){
    if(val==0)
        pch[0]='\x00';
    cout << "Stroka::Stroka(int val)" << endl;
}

Stroka::Stroka(char ch):len(1), pch(new char[len+1]){
    pch[0]=ch;
    pch[1]='\x00';
    cout << "Stroka::Stroka(char ch)" << endl;
}

Stroka::Stroka(const char* S):len(strlen(S)), pch(new char[len+1]){
    strcpy(pch, S);
    pch[len]='\x00';
    cout << "Stroka::Stroka(const char* S)" << endl;
}

Stroka::Stroka(const Stroka& from):len(strlen(from.pch)),pch(new char[len+1]){
    strcpy(pch, from.pch);
    pch[len]='\x00';
    cout << "Stroka::Stroka(const Stroka& from)" << endl;
}

Stroka::~Stroka(){
    if(pch)
        delete [] pch;
    cout << "Stroka::~Stroka()" << endl;
}

void Stroka::Show(void){
    cout << "pch=" << pch << endl;
    cout << "len=" << len << endl;
}

void Stroka::Clear(void){
    if (pch)
        delete[] pch;
    len = 0;
    pch = new char[len + 1];
    pch[0] = '\x00';
}
