#include"my.h"
int main()
{
	printf("parent running.\n");
	
 	FILE *fp;
	char buf[]="I hate you 3000.";
	pid_t pid;
	pid=vfork();
	if(pid<0)
	{
		perror("fork failed!\n");
		return -1;
	}
	else if(pid==0)
	{
		if((fp=fopen("name2.txt","w+"))==NULL)
		{	
			perror("failed to fopen!\n");
			return  -1;
   		}
		if(fputs(buf,fp)==EOF)
		{
			perror("failed to fputs!\n");
        	return -1;

		}
		printf(" Child process :from  the experiment we can see the fp's address=%16p,pid=%d\n",fp,getpid());
	exit(0);

	}
	else{
		if((fp=fopen("name2.txt","w+"))==NULL)
		{	
			perror("failed to fopen!\n");
			return  -1;
   		}
		if(fputs(buf,fp)==EOF)
		{
			perror("failed to fputs!\n");
        	return -1;

		}
		printf(" Parent process from the experiment we can see the fp's address=%16p,pid=%d\n",fp,getpid());
 	exit(0);
	}
return 0;
}
	

