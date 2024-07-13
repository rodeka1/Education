#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define NUM_ALLOCATIONS 100000

void test_malloc_free(size_t size) {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    for (int i = 0; i < NUM_ALLOCATIONS; ++i) {
        void* ptr = malloc(size);
        if(ptr==NULL)
            printf("NULL on %luKB\n", size/1024);
        free(ptr);
    }

    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    double elapsed = seconds + microseconds * 1e-6;

    printf("%luKB %fsec\n", size/1024, elapsed);
}

int main() {
    for (size_t size = 1; size <= 8192*1024; size *= 2)
        test_malloc_free(size*1024);
    return 0;
}
