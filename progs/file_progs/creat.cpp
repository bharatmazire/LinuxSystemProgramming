#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>

int main(int argc, char *argv[])
{
	int fd;

	//fd = creat("test.txt", S_IRUSR | S_IWUSR | S_IRWXU);
	fd = creat("test.txt", S_IRWXU | S_IRWXG | S_IRWXO);
	if (-1 == fd)
	{
		printf("File open failed for error %s\n", strerror(errno));
		return -1;
	}

	lseek(fd, 15, SEEK_SET);
	write(fd, "Hello", 5);
	close(fd);
	return 0;
}

