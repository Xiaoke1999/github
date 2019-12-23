#include"my.h"
void sigoutine(int dumo)
{
	switch(dumo)
	{
		case 1:
			printf("Get a signal SIGHUP\n")	;
			break;	
		case 2:
			printf("Get a signal SIGINT\n")	;	
			break;	
		case 3:
			printf("Get a signal SIGQUIT\n")	;	
			break;		
	}
} 
int main()
{
	printf("process id =%d\n",getpid());
	signal(SIGHUP,sigoutine);	
	signal(SIGINT,sigoutine);	
	signal(SIGQUIT,sigoutine);		
	while(1);
}

