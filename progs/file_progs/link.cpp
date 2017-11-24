#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	int ret;

	ret = link("test.txt", "link.txt");
	if (-1 == ret)
	{
		printf("link system call failed for error %s\n", strerror(errno));
		return -1;
	}
	printf("link system call success.\n");

	sleep(20);

	ret = unlink("link.txt");
	if (-1 == ret)
	{
		printf("unlink system call failed for error %s\n", strerror(errno));
		return -1;
	}
	printf("unlink system call success.\n");

	sleep(10);

	ret = link("mknodtest", "linktest");
	if (-1 == ret)
	{
		printf("link system call failed for error %s\n", strerror(errno));
		return -1;
	}
	printf("link system call success.\n");

	sleep(20);

	ret = unlink("linktest");
	if (-1 == ret)
	{
		printf("unlink system call failed for error %s\n", strerror(errno));
		return -1;
	}
	printf("unlink system call success.\n");

	return 0;
}

