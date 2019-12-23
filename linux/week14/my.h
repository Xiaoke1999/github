#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
#include <signal.h>
#include <sys/types.h>
#include<string.h>
#include<pthread.h>
#include<errno.h>
#include<sys/time.h>
#include<limits.h>
struct sendval{
	int n;
	int s;
}; 
#define NUM 4
