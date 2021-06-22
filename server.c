	#include <sys/types.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <signal.h>
	#include <stdlib.h>

void sighup(){
	printf("I recied a SIGHUP signal\n");
}

void sigint(){
	printf("I recied a SIGINT signal\n");
}

void sigquit(){
	printf("I recied a SIGAUIT signal\n");
	exit(1);
}

int	main()
{
	int pid;
	pid = getpid();
	printf("%d\n", pid);
	while (1){
		signal(SIGQUIT, sigquit);
		signal(SIGHUP, sighup);
		signal(SIGINT, sigint);
	}
	return 0;
}
