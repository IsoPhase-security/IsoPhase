#include <iostream>
#include <linux/futex.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/time.h>

char * ptr;

static long sys_futex(void *addr1, int op, int val1, struct timespec *timeout, void *addr2, int val3)
{
	return syscall(SYS_futex, addr1, op, val1, timeout, addr2, val3);
}

int main(){
	// create shared memory
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key, 1024, IPC_CREAT|0666);
	if (shmid < 0) {
		printf("[ERROR]: something went wrong when caling shmget()...\n");
		return 1;
	}
	//printf("[DEBUG]: shmid is %d\n", shmid);		
	ptr = (char *) shmat(shmid, (void *) 0, 0);
	if (ptr == (char *) -1){
		printf("[ERROR]: something went wrong when calling shmat()...\n");//, explain_shmat(shmid, NULL, 0));
		return 1;
	}
	
	*ptr = 'A';
	printf("CONSUMER: I am about to call futex()...\n");
	int futex_rc = sys_futex(ptr, FUTEX_WAIT, 'A', NULL, NULL, 0);
	printf("CONSUMER: I should was asleep...\n");
	if (futex_rc == 0){
		printf("CONSUMER: I AM AWAKEN!\n");
	}

	if(shmdt(ptr) == -1) {
                printf("something went wrong...\n");
		return 1;
        }
	
	return 0;
}
