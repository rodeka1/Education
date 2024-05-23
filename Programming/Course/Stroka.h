#ifndef __STROKA__
#define __STROKA__

class Stroka{
    protected:
        int len;
        char* pch;
    public:
        Stroka(int);
        Stroka(char);
        Stroka(const char*);
        Stroka(const Stroka&);
        ~Stroka();
        void Show(void);
        void Clear(void);
};

#endif