	#include <sys/types.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <signal.h>
	#include <stdlib.h>

int yex;
int num[8];

void siguser1()
{
	num[yex] = 0;
	yex++;
}

void siguser2()
{
	num[yex] = 1;
	yex++;
}

int	main()
{
	int pid;

	yex = 0;
	pid = getpid();
	printf("%d\n", pid);
	signal(SIGQUIT, siguser1);
	signal(SIGHUP, siguser2);
	if (yex > 7)
	{
		for(int i = 0; i < 8; i++)
			printf("%d |", num[i]);
		printf("\n");
		yex = 0;
	}
	pause();
	return 0;
}
