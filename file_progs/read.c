#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
//#include"constant.h"
#define BUFFER_SIZE 1024

int main(int argc,char **argv)
{
	int ret;
	int fd;
	char buffer[BUFFER_SIZE + 1];
	int length;

	if( argc != 3 )
	{
		printf("usage : %s <file_path> <length>\n",argv[0]);
		exit(-1);
	}
	
	length = atoi(argv[2]);

	memset( buffer , 0 , sizeof( buffer ) );

	ret = access( argv[1] , F_OK );
	if( 0 != ret )
	{
		return -1;
	}

	fd = open( argv[1] , O_RDONLY );
	
	if ( -1 == fd )
	{
		printf("file open failed. Error = %s \n",strerror(errno));
		return -1;
	}

	ret = read( fd , buffer , length );
	//close( fd );
	if( ret == -1 )
	{
		printf("Error while writing a file");
		close(fd);
		return -1;
	}
	
	printf("data read from %s = %s\n",argv[1],buffer);
	close (fd);
	return 0;
}
