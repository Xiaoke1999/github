#include"my.h"
void *worker(void *arg)
{
	//int TID=syscall(SYS_gettid);
	int TID=pthread_self();
	printf("thread--%d:gettid return %ld\n",TID,TID);
	printf("thread--%d:pthread_self return %p\n",TID,(void *)pthread_self());
	printf("thread--%:I will exit now.\n",TID);
	pthread_exit(NULL);
	return NULL;
}
int main()
{
	pthread_t tid=0;
	int ret;
	ret =pthread_create(&tid,NULL,worker,NULL);
	ret=pthread_join(tid,NULL);
	ret =pthread_create(&tid,NULL,worker,NULL);
	ret=pthread_join(tid,NULL);
	printf("ALL fishished!\n");
	return 0;
	
}
