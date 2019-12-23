#include"my.h"
#define NUM 4
void *fun(void *arg)
{
	int *pt;
	pt=(int*)arg;
	int pl=(int)arg;
	int startnum=pl*100;
	int j;
	int sum=0;
	printf("%d thread : tid %p\n\n",pt,pthread_self());
	for(j=startnum;j<startnum+101;j++)
	{
		sum+=j;
	}
	printf("%d thread's sum=%d\n",pt,sum);
	return NULL;
} 
int main()
{
	pthread_t tid[NUM];
	int i,ret[NUM];
	for(i=0;i<NUM;i++)
	{
		ret[i]=pthread_create(&tid[i],NULL,fun,(void *)i);
		if(ret[i]!=0)
		{
		perror("thread create failed\n");
		return -1;
		}	
		pthread_join(tid[i],NULL);
		
	}
	//pthread_join(tid[i],NULL);
	return 0;
}
