/* A low level imlementation of floating point values stored as a struct and a 
 * float variable inside of a union, allowing the user to set/access values as
 * one and or the other - and as an interesting aside, to determine whether the
 * architeture running the program is little_endian or big-endian - this was 
 * written, compiled and tested on a little-endian system - if the union 
 * four_byte_viewer member float f does not print to -2.0, then the system is
 * big-endian */

#include <stdio.h>
#include "struct_to_float.h"

void print_struct(union four_byte_viewer bv)
{

    printf("\nThe values stored in your struct are: sign: %d\n exponent: %d\n"
           " fraction: %d\n", bv.sf.sign_bit, bv.sf.exponent, bv.sf.fraction);
}

void print_float(union four_byte_viewer bv)
{
    printf("\nYour float value is: %f\n", bv.f);
}
