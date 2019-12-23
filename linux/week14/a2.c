#include"my.h"
void *fun(void *arg)
{
	int i=9;
	printf("tid=%p\n",(unsigned int)pthread_self());
	printf("i=%d,&i=%p\n",i,&i);

	pthread_exit((void*)&i);
}
int main()
{
	pthread_t pid;
	int ret,rv;
	ret=pthread_create(&pid,NULL,fun,NULL);
	if(ret!=0)
{
	perror("failed!\n");
	return -1;
}
	pthread_join(pid,(void*)&rv);
	printf("rv=%d",rv);
	return 0;
}
