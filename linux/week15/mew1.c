#include"my.h"
void *work1(void*);
void *work2(void*);
int c=100;
int main()
{
	int ret;
	pthread_t tid[2];
	ret=pthread_create(&tid[0],NULL,work1,NULL);
	
}
