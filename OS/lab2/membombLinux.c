#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

#define PAGE_SIZE getpagesize()

int main() {
    while(1){
        void *mem = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        memset(mem, 0, PAGE_SIZE);
    }
    return 0;
}
