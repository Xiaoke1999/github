#include"my.h"
#define NUM_THREADS 8
char *message[NUM_THREADS];
struct thread_data{
	int thread_id;
	int sum;
	char *message;
};
struct thread_data thread_data_array[NUM_THREADS];
void *PrintHello(void  *threadarg)
{
	int taskid,sum;
	char *hello_msg;
	struct thread_data *my_data;
	sleep(1);
	my_data=(struct thread_data*)threadarg;
	taskid=my_data->thread_id;
	sum=my_data->sum;
	hello_msg=my_data->message;
	printf("Thread %d:%s Sum=%d\n",taskid,hello_msg,sum);
	pthread_exit(NULL);
}
int main(int argc,char *argv[])
{
	pthread_t threads[NUM_THREADS];
	int *taskids[NUM_THREADS];
	int rc,t,sum;
	sum=0;
	message[0]="1.English:Hello ";
	message[1]="2.English:Hello ";
	message[2]="3.English:Hello ";
	message[3]="4.English:Hello ";
	message[4]="5.English:Hello ";
	message[5]="6.English:Hello ";
	message[6]="7.English:Hello ";
	message[7]="8.English:Hello ";	
	for(t=0;t<NUM_THREADS;t++)
	{
		sum=sum+t;
		thread_data_array[t].thread_id=t;
		thread_data_array[t].sum=sum;
		thread_data_array[t].message=message[t];
		printf("Creating thread %d\n",t);
		rc=pthread_create(&threads[t],NULL,PrintHello,(void*)&thread_data_array[t]);
		if(rc)
		{
			printf("ERROR:return code f is %d\n",rc);
			exit(-1);
			
		}
	pthread_join(threads[t],NULL);
	}
	//pthread_exit(NULL);
}
