
#include <stdio.h>
#include "AGGREGATE.h"

float minf(float *arr, int size)
{

    if (arr == NULL || size <= 0)
    {
        printf("FATAL ERROR in line %d where %s", __LINE__, __FILE__);
        return -1;
    }
    float min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

float maxf(float *arr, int size)
{

    if (arr == NULL || size <= 0)
    {
        printf("FATAL ERROR in line %d where %s", __LINE__, __FILE__);
        return -1;
    }
    float max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

float sumf(float *arr, int size)
{

    if (arr == NULL || size <= 0)
    {
        printf("FATAL ERROR in line %d where %s", __LINE__, __FILE__);
        return -1;
    }
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

float avgf(float *arr, int size)
{

    if (arr == NULL || size <= 0)
    {
        printf("FATAL ERROR in line %d where %s", __LINE__, __FILE__);
        return -1;
    }
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    float avg = sum / size;
    return avg;
}

float pseudo_avgf(float *arr, int size)
{

    if (arr == NULL || size <= 0)
    {
        printf("FATAL ERROR in line %d where %s", __LINE__, __FILE__);
        return -1;
    }
    float min = minf(arr, size);
    float max = maxf(arr, size);

    float pseudo_avg = (min + max) / 2;

    return pseudo_avg;
}