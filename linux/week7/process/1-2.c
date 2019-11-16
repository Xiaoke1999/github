#include"my.h"
static void fun1(void)
{
	printf("invoked callbackfun!\n");
	
}
main()
{	
	FILE *fp;
	char buf[]="HELLO\n";
	atexit(fun1);
	printf("%s",buf);
	
	if((fp=fopen("text2.txt","w"))==NULL)
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
