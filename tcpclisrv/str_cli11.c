#include "unp.h"

/* sec 5.13, fig 5-14, page 114 */
void str_cli(FILE *fp, int sockfd){
    char sendline[MAXLINE], recvline[MAXLINE];

    while(NULL != Fgets(sendline, MAXLINE, fp)){
        Writen(sockfd, sendline, 1);
        sleep(1);
        Writen(sockfd, sendline+1, strlen(sendline)-1);

        if(0 == Readline(sockfd, recvline, MAXLINE)){
            fprintf(stderr, "str_cli: server terminated prematurely");
            exit(EXIT_FAILURE);
        }

        Fputs(recvline, stdout);
    }
}
