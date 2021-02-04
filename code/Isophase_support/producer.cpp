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
	// we don't need to write anything to the shared memory to wake the other process...
	//*ptr = 'B';
	int futex_rc = sys_futex(ptr, FUTEX_WAKE, 1, NULL, NULL, 0);
	if (futex_rc == -1){
		printf("CONSUMER: something went wrong when waking up another thread...\n");
	}

	if (shmdt(ptr) == -1){
		printf("something went wrong when detaching...\n");
		return 1;
	}

	printf("PRODUCER: detached from shared memory\n");

	return 0;
}
