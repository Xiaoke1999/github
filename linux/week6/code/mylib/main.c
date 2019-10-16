#include "my.h"
int main()
{
	int i,a[5];
	srand((int)time(0));
	for(i=0;i<5;i++)
	{
		a[i]=rand()%200+1;
	}
	
	show(a,5);	
	printf("max=%d\n",MAX(a,5));
	printf("sum=%d\n",sum(a,5));
	return 0;
}
