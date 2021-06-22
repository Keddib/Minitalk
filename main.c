#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int i = 0;

// void forkexample()
// {
// 	int a;
//     // child process because return value zero
// 	if (fork() == 0) {
//     	a = a + 5;
//     	printf("%d, %d\n", a, &a);
// 	}
// 	else {
//     	a = a - 5;
//     	printf("%d, %d\n", a, &a);
// 	}
// }
int main()
{
    pid_t cpid;
    if (fork()== 0)
	{
		printf("hello\n");
		exit(0);           /* terminate child */
	}
    else
		printf("Parent pid = %d\n", getpid());
    cpid = wait(NULL); /* reaping parent */
    printf("Child terminated = %d\n", cpid);
    return 0;
}
