#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	int ret=0; 
	printf("Before calling pid%d,ppid%d\n",getpid(),getppid());
	execl("/home/xiaoke/github/linux/week7/process/test1","./test1","123","456",NULL);
	/*ret=system("/home/xiaoke/github/linux/week7/process/test1");*/
	printf("after calling !\n");
	sleep(3);
	return 0;
}

