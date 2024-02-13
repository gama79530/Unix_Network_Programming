#include "unp.h"

/* sec 5.9, fig 5-7, page 106 */
void sig_chld(int signo){
    pid_t pid;
    int	stat;

    pid = wait(&stat);
    printf("child %d terminated\n", pid);   /* Using printf in signal handler is not appropriate. Here is an simple example. */
}