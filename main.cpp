#include <windows.h>
#include <cstdio>

int main() {
    SetEnvironmentVariableA("OPENSSL_ia32cap", "~0x200000200000000");

    char launcherPath[MAX_PATH];
    char gamePath[MAX_PATH];

    GetModuleFileNameA(nullptr, launcherPath, MAX_PATH);

    if (char *lastSlash = strrchr(launcherPath, '\\')) {
        *(lastSlash + 1) = '\0';
    }

    strcpy(gamePath, launcherPath);
    strcat(gamePath, "Titanfall2.exe");

    if (GetFileAttributesA(gamePath) == INVALID_FILE_ATTRIBUTES) {
        printf("ERROR: Titanfall2.exe not found!\n");
        printf("Please place this launcher in the same directory as Titanfall2.exe\n");
        system("pause");
        return 1;
    }

    STARTUPINFOA si = {sizeof(si)};
    PROCESS_INFORMATION pi;

    if (!CreateProcessA(gamePath, nullptr, nullptr, nullptr, FALSE, 0, nullptr, nullptr, &si, &pi)) {
        printf("Failed to launch Titanfall 2. Error code: %lu\n", GetLastError());
        system("pause");
        return 1;
    }

    printf("Titanfall 2 launched successfully!\n");
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
