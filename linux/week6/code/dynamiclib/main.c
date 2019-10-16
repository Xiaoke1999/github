#include "my.h"
int main()
{
	int a[5]={323,-77,34,12,56};
	show(a,5);	
	printf("max=%d\n",MAX(a,5));
	printf("sum=%d\n",sum(a,5));
	return 0;
}
