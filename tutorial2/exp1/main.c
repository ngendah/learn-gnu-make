#include <stdio.h>

#include "base.h"


float add(const float x, const float y)
{
    return x + y;
}


void main(int argc, char* argv[])
{
    const float result = add(2.0, 3.0);
    printf("result=%.2f\n", result);
}
