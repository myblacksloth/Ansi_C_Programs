#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "elabconfig.c"



int main()
{


        config* c = (config*)malloc(sizeof(config));
        if (c == NULL)
        {
                return 1;
        }

        int ret = 0;

        ret = makeConf(c);

        return 0;
}

