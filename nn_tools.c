#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

float random()
{
    int a;
    srand(time(NULL));
    a = rand();
    if (a % 2 == 0)
    {
        return -(float)rand() / (float) RAND_MAX;
    }
    else
    {
        return (float)rand() / (float) RAND_MAX;
    }
}

float sigmoid(float a)
{
    return (1 / (1 + exp(-a)));
}

float derivate_sigmoid(float a)
{
    return a * (1 - a);
}

int max_array(float *a, int n)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }
    return m;
}
