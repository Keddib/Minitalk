	#include <sys/types.h>
	#include <unistd.h>
	#include <stdio.h>
	#include <signal.h>
	#include <stdlib.h>


int main(int argc, char **argv)
{
	int pid;

	argv[0] = NULL;
	if (argc == 2)
	{
		pid = atoi(argv[1]);
		kill(pid, SIGHUP);
		sleep(3); /* pause for 3 secs */
		kill(pid, SIGINT);
		sleep(3); /* pause for 3 secs */
        kill(pid, SIGQUIT);
		sleep(3); /* pause for 3 secs */

	}
	return (0);
}
