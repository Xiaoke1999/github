#include"my.h"
void *work1(void*);
void *work2(void*);
int c=100;
sem_t mutex,full;
int main()
{
	int ret;
	pthread_t tid[2];
	ret=sem_init(&mutex,0,1);
	ret=sem_init(&full,0,0);
	//pthread_mutex_init(&mutex,NULL);
	ret=pthread_create(&tid[0],NULL,work1,NULL);
	if(ret!=0)
	{
		perror("thread1 create failed!\n");
		exit(1);
	}
	ret=pthread_create(&tid[1],NULL,work2,NULL);
	if(ret!=0)
	{
		perror("thread2 create failed!\n");
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
	
	
	while(1)
	{
		sem_wait(&mutex);
		if(c>0)
		{
			usleep(1000);
			printf("thread 1 sell ticket:%d,mutex=%u,full=%u\n",c--,&mutex,&full);
			sem_post(&full);
		}
		else{
			sem_post(&full);
			break;
		}
		//ret=pthread_yield();
	}
	return NULL;
}
void *work2(void *arg)
{
	//sem_wait(&full);
	int ret;
	while(1)
	{
		sem_wait(&full);

		if(c>0)
		{
			//sem_post(&mutex);
			usleep(1000);
			printf("thread 2 sell ticket:%d,mutex=%u,full=%u\n",c--,mutex,full);
			sem_post(&mutex);
		}
		else{
			sem_post(&mutex);
			break;
		}
		//ret=pthread_yield();
	}
	return NULL;
}
