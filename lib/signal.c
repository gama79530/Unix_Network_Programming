#include "unp.h"

/* sec 5.8, fig 5-6, page 104 */
Sigfunc *signal(int signo, Sigfunc *func){
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if(SIGALRM == signo){
    #ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;   /* SunOS 4.x */
    #endif
    }else{
    #ifdef SA_RESTART
        act.sa_flags |= SA_RESTART; /* SVR4, 44BSD */
    #endif
    }
    if(0 > sigaction(signo, &act, &oact)){
        return SIG_ERR;
    }
    return oact.sa_handler;
}

Sigfunc *Signal(int signo, Sigfunc *func){
    Sigfunc	*sigfunc = NULL;

    if(SIG_ERR == (sigfunc = signal(signo, func))){
        perror("signal error");
    }
    return sigfunc;
}
