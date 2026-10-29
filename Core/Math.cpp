#include "Math.hpp"

unsigned int NextPowerOfTwo(unsigned int value) {
    --value;
    value |= value >> 1;
    value |= value >> 2;
    value |= value >> 4;
    value |= value >> 8;
    value |= value >> 16;
    return value + 1;
}

bool IsPowerOfTwo(unsigned int value) {
    return value != 0 && (value & (value - 1)) == 0;
}