#include <stdio.h>

/*

$value    =0x125  =0x1234   &=0x1234
$memValue **=10   *==10     ==10       +-----------+
$var      pptr+->ptr+----> var+------->+   10      |
$address 0x126   0x125                 |           |
                                       +-----------+
                                         0x1234


*/

int main()
{

    int var = 10;

    printf("%d , %u\n", var, &var);

    int *ptr = &var;

    printf("\n%d , %u , %u\n", *ptr, ptr, &ptr);

    int **pptr = &ptr;

    printf("\n%d , %u , %u\n", **pptr, pptr, &pptr);

    // printf("%d\n", );

    return 0;
}

/**** $output>
10 , 3880540628

10 , 3880540628 , 3880540616

10 , 3880540616 , 3880540608
 ****/