#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char **argv)
{
	int ret;
	if(argc!=2)
	{
		printf("usage : %s <file_path>\n",argv[0]);
		exit(-1);
	}
	
	ret = access(argv[1],F_OK);
	if( 0 != ret )
	{
		printf("File %s is not exists\n",argv[1]);
		return -1;
	}
	else
		printf("File exists\n");

	ret = access(argv[1],R_OK);
	if( 0 != ret )
		printf("File %s is not having read permission \n",argv[1]);
	else
		printf("File having read permission\n");
	
	ret = access(argv[1],W_OK);
	if( 0 != ret )
		printf("File %s is not having write permission \n",argv[1]);
	else
		printf("File having write permission\n");

	ret = access(argv[1],X_OK);
	if( 0 != ret )
		printf("File %s is not having execute permission \n",argv[1]);
	else
		printf("File having execute permission\n");

	ret = access(argv[1],R_OK|W_OK|X_OK);
	if( 0 != ret)
		printf("File %s is not having all permissions \n",argv[1]);
	else
		printf("File haivng all permission \n");
	return 0;
}
