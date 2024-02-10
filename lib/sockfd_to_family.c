#include "unp.h"

/* sec 4.10, fig 4-19, page 96 */
int sockfd_to_family(int sockfd){
    struct sockaddr_storage ss;
    socklen_t len;

    len = sizeof(ss);
    if(0 > getsockname(sockfd, (SA*)&ss, &len)){
        return -1;
    }

    return ss.ss_family;
}
