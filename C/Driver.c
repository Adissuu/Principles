#include <stdio.h>
#include <stdlib.h>
#include "AGGREGATE.h"
#include "AGGREGATE.c"


void q4(float *five_numbers, float *ten_numbers)
{
    float (*aggregates[5])(float *, int size) = {&minf, &maxf, &sumf, &avgf, &pseudo_avgf};
    float result;

    int i = 0;
    for (i = 0; i < 5; i++)
    {
        result = aggregates[i](five_numbers, 5);
        printf("Result of the function #%d on the array of five numbers: %.2f.\n\n", i + 1, result);

        result = aggregates[i](ten_numbers, 10);
        printf("Result of the function #%i on the array of ten numbers: %.2f.\n\n", i + 1, result);
    }
}

int main()
{
    float five_numbers[5] = {6, 7, 5, 4, 3};
    float ten_numbers[10] = {10, 20, 41, 21, 56, 234, 67, 87, 99, 76};

    q4(five_numbers, ten_numbers);
    
    return 1;
}