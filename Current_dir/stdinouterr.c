#include<stdio.h>
#include<unistd.h>

int main(int argc, char * argv)
{
	char buf[5] = "hi";
	read(0,buf,4);
	write(1,buf,4);
	write(2,buf,4);
	return 0;
}
