#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc,char **argv)
{
	int ret;
	int fd;

	if(argc!=3)
	{
		printf("usage : %s <file_path> <message>\n",argv[0]);
		exit(-1);
	}
	
	ret = access(argv[1],F_OK);
	if( 0 != ret )
	{
		fd = open(argv[1],O_CREAT|O_WRONLY,0666);
	}
	else
	{
		fd = open(argv[1],O_APPEND | O_WRONLY);
	}

	if ( -1 == fd )
	{
		printf("file open failed. Error = %s \n",strerror(errno));
		return -1;
	}
	int length = strlen(argv[2]);
	ret = write(fd,argv[2],length);
	if(ret != length)
	{
		printf("Error while writing a file");
		close(fd);
	}
	return -1;
	
}
