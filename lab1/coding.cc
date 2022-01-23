#include<coding.h>

#define SHIFT_CHAR 5

unsigned char encode(unsigned char c)
{
    unsigned int c_as_int = static_cast<unsigned int>(c);
    c_as_int += SHIFT_CHAR;
    c = static_cast<unsigned char>(c_as_int);
    return c;
}
unsigned char decode(unsigned char c)
{
    unsigned int c_as_int = static_cast<unsigned int>(c);
    c_as_int -= SHIFT_CHAR;
    c = static_cast<unsigned char>(c_as_int);
    return c;
}
