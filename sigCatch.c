#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int SIG1 = 0;
int SIG2 = 0;
int SIG3 = 0;

void handler(int signo) {
	if(signo == SIGUSR1) {
	SIG1++;
	printf("sigUsr1 received\n");
	printf("USR1 total: %d,", SIG1);
	SIG3 = 0;
	}
	else if(signo == SIGUSR2) {
	SIG2++;
	printf("sig 2 received.\n");
	printf("SIG2 total: %d,", SIG2);
	SIG3 = 0;
	}
	else if(signo == SIGINT) {
	SIG3++;
	printf("sig3 received \n");
	}
}
	

void main() {
	
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	signal(SIGINT, handler);
	while(1) {

	if(SIG2 == SIG1 + 2){
	printf("two more SIG2 than 1 received.");
	exit(0);
	}
	else if(SIG3 == 2) {
	printf("Two Sigints received. \n");
	exit(0);
	}
	}

}

