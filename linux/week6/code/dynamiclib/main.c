#include "my.h"
#include<dlfcn.h>
#include<stdlib.h>
int main()
{
    void  *handle;
	int(*f1)();
	int(*f2)();
	int(*f3)();
	char *error;

	int a[5]={323,-77,34,12,56};
	handle=dlopen("/home/xiaoke/test4/dynamiclib/libdynamiclib.so",RTLD_LAZY);
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
	f2=dlsym(handle,"MAX");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"error,%s\n",error);
		exit(1);
	}
	f3=dlsym(handle,"sum");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr,"error,%s\n",error);
		exit(1);
	}
	
	f1(a,5);
	printf("max=%d",f2(a,5));
	printf("sum=%d",f3(a,5));
	if(dlclose(handle)<0){
		fprintf(stderr,"error,%s\n",error);
		exit(1);
	}
	return 0;
}
