//Diego Hernández 1627118
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>

int main()
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    assert(strftime(s, sizeof(s), "%c", tm));
    int fork_res;

    printf("PROCESS TYPE\t PID\t PPID\t TIME\n");
    
    fork_res = fork();

    fork();
    fork();

    if (fork_res >= 1)
    {
        printf("Proceso Padre\t %d\t %d\t %s\n", getpid(), getppid(), s);
    }
    else if (fork_res == 0)
    {
        printf("Proceso Hijo\t %d\t %d\t %s\n", getpid(), getppid(), s);
    }
    else
    {
        printf("ERR0R");
    }
    return 0;
}