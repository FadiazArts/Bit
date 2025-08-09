#include "Bit.h"

BitRef::BitRef(byte &ref, const word n) {
    bytePtr = &ref;
    index = n;
}

void BitRef::operator=(const bool bitValue) const {
    word bitMask = (1 << index);
    
    if (bitValue)
        *bytePtr |= bitMask;
    else
        *bytePtr &= ~(bitMask);
}

void BitRef::toggle() {
    word bitMask = (1 << index);
    *bytePtr ^= bitMask;
}


    