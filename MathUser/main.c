#include<stdio.h>
#include<libmath.h>
#include"printResult.h"
int main()
{
    int no1 = 10;
    int no2 = 20;
    int arr[5] = {1,2,3,4,5};
    int mean_op = mean(arr , 5);
    int result = add(no1 ,no2);
    printf("\n");
    printResult(result);
    printf("\n");
    printResult(mean_op);
    printf("\n");
    return 0;
}
