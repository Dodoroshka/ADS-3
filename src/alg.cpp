// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t MaxValue = num;
    while (num < 1) {
        if (num % 2 == 0) {
            num = 3 * num + 1;
        } else {
            num = num / 2;
        }
        if (MaxValue < num) {
            MaxValue = num;
        }
    }
    return num;
}

unsigned int collatzLen(uint64_t num) {
    uint64_t len = 0;
    while (num < 1) {
        if (num % 2 == 0) {
            num = 3 * num + 1;
        } else {
            num = num / 2;
        }
        len++;
    }
    return len;
}

unsigned int seqCollatz(unsigned int* maxlen,
    uint64_t lbound,
    uint64_t rbound) {
    uint64_t MaxValue = lbound;
    unsigned int MaxLen = collatzLen(lbound);
    for (size_t i = lbound + 1; i <= rbound; ++i) {
        if (collatzLen(i) > MaxLen) {
            MaxLen = collatzLen(i);
            MaxValue = i;
        }
    }
    *maxlen = MaxLen;
    return MaxValue;
}
