/* Simple test suite for struct_to_float.c module */

#include <stdio.h>
#include "struct_to_float.h"

int main(void)
{
    union four_byte_viewer test_bv;

    test_bv.sf.sign_bit = 1;

    test_bv.sf.exponent = 128;

    test_bv.sf.fraction = 0;

    print_struct(test_bv);

    print_float(test_bv);

    int a = 0x12345678;
    unsigned char *ch = (unsigned char *)(&a);
    if (*ch == 0x78)
        printf("\nLittle-endian\n");
    else 
        printf("\nBig-endian\n");

    printf("The first stored byte of a is: %X\n", *ch);

    return 0;
}
