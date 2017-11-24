#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char ** argv)
{
  // check for correct input
  if( argc != 3 )
  {
    printf("\n Incorrect input. \n It should be < execuatle name > < source path > < destination path >\n");
    return -1;
  }

  int ret;
  
  // check for file access permission. It will also check whether file exist or not
  ret = access(argv[1],F_OK);
  if( ret == -1 )
  {
    printf("\n path %s does not exist or user have no access ",argv[1]);
    return -1;
  }
  
  
  
  int fd , fd1;
  char buf[1];
  
  memset( buf , 0 , sizeof( buf) ); 		// clearing memory 
  
  fd = open(argv[1],O_RDONLY);				// opening source file with read only mode
  fd1 = open(argv[2],O_CREAT|O_RDWR);		// creating destination file with read write mode 
  
  while(ret = read(fd,buf,1))
  {
    if(ret == -1 )
    {
      printf("Error while reading file ");
      return -1;
    }
   ret = write(fd1 ,buf, 1);
    if(ret == -1 )
    {
      printf("Error while writing file ");
      return -1;
    }
  }

//  for reading content written in destination file
/*  
  lseek(fd1 , 0 , SEEK_SET);
  printf("lseek done %d",fd1);
  while(ret = read(fd1,buf,1))
  {
    if(ret == -1 )
    {
      printf("Error while reading file ");
      return -1;
    }
  printf("%s",buf);
  }
*/
  close(fd);
  close(fd1);
  
  printf("\n");
  return 0;
}
