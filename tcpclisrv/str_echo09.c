#include "unp.h"
#include "sum.h"

/* sec 5.18.2, fig 5-20, page 119 */
void str_echo(int sockfd){
    struct args args;
    struct result result;
    ssize_t	n;

    while(1){
        if(0 == (n = Readn(sockfd, &args, sizeof(args)))){
            return; /* connection closed by other end */
        }
        result.sum = args.arg1 + args.arg2;
        Writen(sockfd, &result, sizeof(result));
    }
}
