#ifndef STRUCT_TO_FLOAT_H
#define STRUCT_TO_FLOAT_H

#include <stdio.h>

/* This program was compiled and tested on a little-endian architecture 
 * (AMD 64), so struct std_float members must be stored in the opposite way
 * that the gcc generally interprets floating point representations in memory,
 * with the most significant field, the sign_bit, stored last, and the least
 * significant field, the fraction, stored first - this raises some portability
 * issues that could perhaps be solved with macros */
struct std_float {
     unsigned int fraction: 23;
     unsigned int exponent: 8;
     unsigned int sign_bit: 1;
};

union four_byte_viewer {
    struct std_float sf;
    float f;
};

void print_struct(union four_byte_viewer bv);

void print_float(union four_byte_viewer bv);

#endif
