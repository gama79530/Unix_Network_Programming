#include "unp.h"

/* sec 5.10, fig 5-11, page 110 */
void sig_chld(int signo){
    pid_t pid;
    int	stat;
    while(0 < (pid = waitpid(-1, &stat, WNOHANG))){
        printf("child %d terminated\n", pid);
    }
    return;
}
