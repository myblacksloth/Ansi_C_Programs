#include <stdio.h>
// Antonio Maulucci 2019
/*

                             +-------------------+
         +---+               |                   |
a+------>+32 |               |  +-+tmp+-------+  |
         +---+               |  |    +-----+  |  |
           0x1 +-----+       |  |   b| 32  |  |  |
                     ++swap()|  |    +-----+  |  |
         +---+       |       |  |   a+-----+  |  |
b+------>+16 |0x2 +--+       |  |    | 16  <--+  |
         +----<-----------------+    +-----+     |
                             |                   |
                             +-------------------+


*/

void swap(int *a, int *b) // change the values inside memory's areas using pointers
{
    int tmp = *b; //take value (int) from b pointer
    *b = *a; // set the valaue of b pointer to a pointer's value
    *a = tmp; // set the a pointer's value to tmp
}

int main()
{

    int a=32, b=16;

    printf("\na = %d , b = %d\n", a, b);

    swap(&a, &b); // pass addresses to function

    printf("\na = %d , b = %d\n", a, b);

    return 0;
}