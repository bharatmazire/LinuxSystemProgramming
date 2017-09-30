#include<printf.h>
#include<stdlib.h>

int my_main()
{
 printf("\n Hello Universe \n");
 exit(0);
}

// execition steps :
// gcc -save-temps my_new_main.c or gcc my_new_main.c --save-temp
// ld -lc -dynamic-linker /lib
