#ifndef ARRAYCOUNT_HPP
#define ARRAYCOUNT_HPP

// The array is taken by reference so it does not decay to a pointer
template <typename T, unsigned int kCount>
constexpr unsigned int ArrayCount(const T (&)[kCount]) {
    return kCount;
}

#endif // ARRAYCOUNT_HPP