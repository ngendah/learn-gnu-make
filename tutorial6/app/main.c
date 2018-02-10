#include <stdio.h>
#include "lib.h"


int main(int argc, char* argv[])
{
    const float result = add(2.0, 3.0);
    printf("result=%.2f\n", result);
    return 0;
}
