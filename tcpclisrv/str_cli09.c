#include "unp.h"
#include "sum.h"

/* sec 5.18.2, fig 5-19, page 118 */
void str_cli(FILE *fp, int sockfd){
    char sendline[MAXLINE];
    struct args args;
    struct result result;

    while(NULL != Fgets(sendline, MAXLINE, fp)){
        if(2 != sscanf(sendline, "%ld %ld", &args.arg1, &args.arg2)){
            printf("invalid input: %s\n", sendline);
            continue;
        }
        Writen(sockfd, &args, sizeof(args));

        if(0 == Readn(sockfd, &result, sizeof(result))){
            fprintf(stderr, "str_cli: server terminated prematurely");
            exit(EXIT_FAILURE);
        }

        printf("%ld\n", result.sum);
    }
}
