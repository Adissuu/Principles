#include <stdio.h>
#include <stdlib.h>
#include "AGGREGATE.h"

void pointers(float *five_numbers, float *ten_numbers)
{
    float (*aggregates[5])(float *, int size) = {&minf, &maxf, &sumf, &avgf, &pseudo_avgf};
    float result;

    int i = 0;
    for (i = 0; i < 5; i++)
    {
        result = aggregates[i](five_numbers, 5);
        printf("Result of the current function on the array of five numbers: %.2f.\n\n", result);

        result = aggregates[i](ten_numbers, 10);
        printf("Result of the current function on the array of ten numbers: %.2f.\n\n", result);
    }
}
