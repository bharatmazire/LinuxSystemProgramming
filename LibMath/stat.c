#include<libmath.h>

int mean(int *pArr , int size)
{
    int sum = 0;

    for (int itr = 0 ; itr < size ; itr ++)
    {
       //sum += pArr[itr];
       sum = add(sum , pArr[itr]);
    }

    return sum / size;
}
