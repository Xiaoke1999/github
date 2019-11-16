/*#include"my.h"
int main(int argc,char const *argv[])
{
int cnt=1;
pid_t pid=fork();
if(pid<0)
{
printf("process error!\n");
return 1;
}
else if(pid==0)
{
printf("child process id=%d count=%d cntaddress=%16p\n",getpid(),cnt,&cnt);
}
else
{
printf("parent process id=%d count=%d cntaddress=%16p\n",getpid(),cnt,&cnt);
}
return 0;
}*/
#include <unistd.h>  
#include <stdio.h>  
int main(void)  
{  
   int i=0;  
   for(i=0;i<3;i++){  
       pid_t fpid=fork();  
       if(fpid==0)  
           printf("son\n");  
       else  
           printf("father\n");  
   }  
   return 0;  
  
}  
