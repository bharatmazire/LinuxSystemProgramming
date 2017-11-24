#include<stdio.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<string.h> 
#include<stdlib.h>

struct stud_info 
{
 	int roll_no;
	int std;
	char name[8];
};

int ret_fd(char f_name[])
{
	int ret , fd;
	ret = access(f_name,F_OK|R_OK|W_OK); 
	if(ret == -1) 
	{ 
		printf(" Entered file is not present \n or \n user have no access \n so we are creating new file ...."); 
		fd = open(f_name,O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR); 
	} 
	else 
	{ 
		printf("File present and opening in append mode"); 
		fd = open(f_name,O_APPEND|O_WRONLY,S_IRUSR|S_IWUSR);
	} 
	return fd;
}


int main(int argc , char ** argv)
{
	//... for 1st validation of valid arguments
	if( argc != 2 ) 
	{
		printf("Invalid number of arguments \n please provide <executable name> <student filename> \n");
		return -1;
	} 
	//...
	
	
	int fd; 
	char buf[4];
	fd = ret_fd(argv[1]);		// getting file descriptor.
	
	struct stud_info s1; 
	s1.roll_no = 1; 
	s1.std = 1; 
	strcpy(s1.name,"bsm"); 
	//strcpy(s1.div,"a"); 
  printf("\n%d,%d,%s",s1.roll_no,s1.std,s1.name); 
	//buf = (char)s1.roll_no;
	int ret;
	ret = write(fd,&s1,sizeof(struct stud_info)); 
	//ret = write(fd,&s1,si));
	
	if(ret == -1) 
	{ 
		printf("\nerror while writing"); 
		return -1; 
	} 
	
	close(fd); 
	printf("\n"); 
	return 0; 
}
