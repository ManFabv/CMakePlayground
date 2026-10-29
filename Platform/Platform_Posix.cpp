#include "Platform.hpp"

// sysconf
#include <unistd.h>

const char* GetPlatformName() {
    // small differences INSIDE the POSIX family can stay as #if; whole platforms get their own file
#if defined(__APPLE__)
    return "macOS";
#else
    return "POSIX";
#endif
}

unsigned int GetLogicalCoreCount() {
    const long online_core_count = sysconf(_SC_NPROCESSORS_ONLN);
    return (online_core_count > 0) ? static_cast<unsigned int>(online_core_count) : 1u;
}