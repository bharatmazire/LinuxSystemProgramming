#include<stdio.h>
#include<dlfcn.h>

int main(int argc , char ** argv)
{
	if(argc != 3)
	{
		printf("Usage %s <lib_path>",argv[0]);
		return -1;
	}

	void *handle;
	typedef int (*pfunAdd) (int,int);
	pfunAdd fptr;
	
	handle = dlopen(argv[1],RTLD_LAZY);

	if(NULL == handle)
	{
		fprintf(stderr,"dlopen failed : %s \n",dlerror());
		return -1;
	}

	fptr = (pfunAdd) dlsym(handle,argv[2]);

	if(fptr == NULL)
	{
		printf("function not present !!");
		dlclose(handle);
		return -1;
		
	}

	printf("Result = %d \n",fptr(10,20));	
	
	dlclose(handle);
	
	return 0;
}
