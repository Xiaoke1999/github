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

#include<semaphore.h>
#define LOOP 10000000
#define NUM 4
#define NT 100
