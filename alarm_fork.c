
#include <stdio.h>
#include <sys/types.h>
#include <wait.h>

int main(int argc, char *argv[])
{
    int status;
    char line[128];
    int seconds;
    pid_t pid;
    char message[64];
    
    while (1)
    {
	printf("[%d] Alarm> ", getpid());
	if (fgets(line, sizeof(line), stdin) == NULL)
	{
	    exit(0);
	}
	if (strlen(line) <= 1)
	{
	    continue;
	}
	if (sscanf(line, "%d %64[^\n]", &seconds, message) < 2)
	{
	    fprintf(stderr, "[%d] Bad command\n", getpid());
	} 
	else
	{
	    // 可以这样理解：这是一个进程链表的结构，fork接口返回的是子进程的id;
	    // 如果返回0,表明处于子进程中，因为子进程后面再指向新的子进程
	    // 如果返回有效值，则处于父进程中，此时pid指向该进程的子进程
	    // [NOTE] fork接口的特殊点在于，在生成子进程的期间它只执行了一遍。
	    pid = fork();
	    printf("[%d] fork() pid = %d\n", getpid(), pid);
	    if (pid == (pid_t)-1)
	    {
		printf("[%d] Fork", getpid());
	    }
	    if (pid == (pid_t)0)
	    {
		sleep(seconds);
		printf("[%d] [In child] (%d) %s\n", getpid(), seconds, message);
		exit(0); // 如果不退出子进程，它将会和父进程交替promt alarm输入
	    }
	    else 
	    {
		printf("[%d] [In parent] waiting for pid=%d ...\n", getpid(), pid);
		do
		{
		    pid = waitpid((pid_t)-1, NULL, WNOHANG);
		    if (pid == (pid_t)-1)
		    {
			printf("Wait for child\n");
		    }
		    printf("[%d] waitpid()=%d\n", getpid(), pid);
		} while (pid != (pid_t)0);
	    }
	}
    }

    return 0;
}
