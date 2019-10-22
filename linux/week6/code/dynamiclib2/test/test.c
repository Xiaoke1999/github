#include<stdio.h>
#include"/home/xiaoke/github/linux/week6/code/dynamiclib2/my.h"
#include<stdlib.h>
#include<dlfcn.h>
int main()
{
	void  *handle;
	int(*f1)();
	int(*f2)();
	int(*f3)();
	int(*f4)();
	char *error;

	int a[N];
	handle=dlopen("/home/xiaoke/github/linux/week6/code/dynamiclib2/libtest.so",RTLD_LAZY);
	if(!handle)
	{
		perror("load error\n");
		exit(1);
	}
	f1=dlsym(handle,"show");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"error,%s\n",error);
		exit(1);
	}
	f2=dlsym(handle,"init");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"error,%s\n",error);
		exit(1);
	}
	f3=dlsym(handle,"max");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"error,%s\n",error);
		exit(1);
	}
	f4=dlsym(handle,"sum");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"error,%s\n",error);
		exit(1);
	}
	printf("before init\n");
	(*f1)(a,N);
	(*f2)(a,N);
	printf("after init\n");
    (*f1)(a,N);
	printf("max=%4d",(*f3)(a,N));
	printf("max=%4d",(*f4)(a,N));
	
	dlclose(handle);
	return 0;

}
