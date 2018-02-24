#include <stdio.h>

#include "add.h"
#include "subtract.h"


void main(int argc, char* argv[])
{
    const float result = add(2.0, 3.0);
    printf("result=%.2f\n", result);
}
