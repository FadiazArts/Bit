#include <Arduino.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef BIT_HEADER
#define BIT_HEADER

#ifndef TYPEDEF_INTEGRAL_TYPE
#define TYPEDEF_INTEGRAL_TYPE
    typedef uint8_t byte;
    typedef uint16_t word;
#endif

class BitRef {
private:
    byte* bytePtr;
    word index;
    word bitCount;
public:
    BitRef(byte &ref, const word n);
    void set(const bool bitValue) { return (*this)=bitValue; } 
    void toggle();
    void operator=(const bool bitValue) const;
    operator bool() { return !!(*bytePtr & (1 << index)); }
};


template <word count = 0, typename T = byte>
class Bit {
private: T* bytePtr;
    static const word byteCount = ((count + 7) / 8);
    byte data[ byteCount ];
public:
    Bit() : bytePtr( data ) { return; }
    Bit(T &ref) : bytePtr( &ref ){ return; }
    void clear() { *bytePtr = 0; }
    BitRef operator[](const word index) { return BitRef(*(bytePtr + ((index)/8)), index % 8); }
};
    
template <word N, typename T> Bit(T) -> Bit<0,T>;
#endif