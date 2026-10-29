#ifndef MATH_HPP
#define MATH_HPP

#include "ArrayCount.hpp"

template <unsigned int kCount>
unsigned int MaxOf(const unsigned int (&values)[kCount]) {
    unsigned int max_value = values[0];
    for (unsigned int i = 1; i < ArrayCount(values); ++i) {
        max_value = (values[i] > max_value) ? values[i] : max_value;
    }
    return max_value;
}

unsigned int NextPowerOfTwo(unsigned int value);

bool IsPowerOfTwo(unsigned int value);

#endif // MATH_HPP