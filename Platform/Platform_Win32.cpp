#include "Platform.hpp"

// windows.h stays inside this .cpp: no other file pays for it (or for its min/max macros)
#include <windows.h>

const char* GetPlatformName() {
    return "Windows";
}

unsigned int GetLogicalCoreCount() {
    SYSTEM_INFO system_info;
    GetSystemInfo(&system_info);
    return static_cast<unsigned int>(system_info.dwNumberOfProcessors);
}