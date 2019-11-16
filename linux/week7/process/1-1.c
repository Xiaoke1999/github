#include"my.h"
static void fun1(void)
{
	printf("invoked callbackfun!\n");
	
}
main()
{	
	FILE *fp;
	char buf[]="HELLO";
	
	printf("%s",buf);
	atexit(fun1);
	if((fp=fopen("text.txt","w"))==NULL)
	{
		perror("fail to open");
		return -1;
	}
	if(fputs(buf,fp)==EOF)
	{
		perror("fail to fputs");
		return -1;
	}
	exit(0);
}
