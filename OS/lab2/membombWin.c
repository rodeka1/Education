#include <stdio.h>
#include <Windows.h>

int main() {
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);
    DWORD PAGE_SIZE = systemInfo.dwPageSize;

    while (1) {
        LPVOID mem = VirtualAlloc(NULL, PAGE_SIZE, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

        if (mem == NULL) {
            DWORD error = GetLastError();
            printf("Error: %lu\n", error);
            return 1;
        }

        memset(mem, 0, PAGE_SIZE);
    }

    return 0;
}
