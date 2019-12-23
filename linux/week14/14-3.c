#include "my.h"

#define size 10
int a[size],b[size];
void max_fun(int *arg)
{
  int *ap=arg;
  int rv,i,k=0;
  for(i=1;i<size;i++){
     if(ap[i]>ap[k])
        k=i;
  }
  pthread_exit((void *)&ap[k]);
}

int main()
{
  pthread_t tid1,tid2;
  int i,rv,**ptr1,**ptr2;
  for(i=0;i<size;i++)
   {
      a[i]=rand();
      b[]
   }
}
