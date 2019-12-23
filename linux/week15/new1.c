#include"my.h"
void *work1(void*);
void *work2(void*);
int c=100;
int main()
{
	int ret;
	pthread_t tid[2];
	ret=pthread_create(&tid[0],NULL,work1,NULL);
	if(ret!=0)
	{
		perror("thread create failed!\n");
		exit(1);
	}
	ret=pthread_create(&tid[1],NULL,work2,NULL);
	if(ret!=0)
	{
		perror("thread create failed!\n");
		exit(1);
	}
	for(int i=0;i<2;i++)
	{
		pthread_join(tid[i],NULL);

	}
	return 0;
}
void *work1(void *arg)
{
	int ret;
	while(1)
	{
		if(c>0)
		{
			usleep(1000);
			printf("thread 1 sell ticket:%d\n",c--);
		}
		else{
			break;
		}
		ret=pthread_yield();
	}
	return NULL;
}
void *work2(void *arg)
{
	int ret;
	while(1)
	{
		if(c>0)
		{
			usleep(1000);
			printf("thread 2 sell ticket:%d\n",c--);
		}
		else{
			break;
		}
		ret=pthread_yield();
	}
	return NULL;
}
