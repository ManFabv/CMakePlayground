#include "Math.hpp"
#include "Platform.hpp"

#include <stdio.h>

int main() {
    printf("Hello from CMake\n");
#if defined(PLAYGROUND_ENABLE_LOGS)
    printf("Debug logs activated\n");
#endif
    
    const unsigned int frame_times[] = {16, 33, 17, 50, 16};
    printf("Worst frame: %u ms\n", MaxOf(frame_times));
#if defined(CORE_HAS_FAST_MATH)
    printf("App sees CORE_HAS_FAST_MATH\n");
#else
    printf("App does not see CORE_HAS_FAST_MATH\n");
#endif

    const unsigned int requested_capacity = 200;
    printf("Capacity %u -> %u (power of 2: %d)\n", requested_capacity, NextPowerOfTwo(requested_capacity),
           IsPowerOfTwo(NextPowerOfTwo(requested_capacity)) ? 1 : 0);
    
    printf("Platform: %s, %u logical cores\n", GetPlatformName(), GetLogicalCoreCount());

    return 0;
}