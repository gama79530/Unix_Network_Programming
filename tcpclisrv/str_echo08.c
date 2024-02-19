#include "unp.h"

/* sec 5.18.1, fig 5-17, page 118 */
void str_echo(int sockfd){
    long arg1, arg2;
    ssize_t	n;
    char line[MAXLINE];

    while(1){
        if(0 == (n = Readline(sockfd, line, MAXLINE))){
            return; /* connection closed by other end */
        }

        if(2 == sscanf(line, "%ld %ld", &arg1, &arg2)){
            snprintf(line, sizeof(line), "%ld\n", arg1 + arg2);
        }else{
            snprintf(line, sizeof(line), "input error\n");
        }

        n = strlen(line);
        Writen(sockfd, line, n);
    }
}
