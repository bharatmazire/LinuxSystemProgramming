
#include "libmath.h"
#include <stdio.h>

int mean(int *pArray, int size) {
	int itr = 0;
	int sum = 0;
	if (NULL == pArray)
		return -1;
	for (; itr < size; itr++)
		sum = add(sum, pArray[itr]);
	return sum/size;
}

