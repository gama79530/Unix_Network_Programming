#include "unp.h"

/* sec 3.8, fig 3-14, page 71*/
char* sock_ntop(const SA *sa, socklen_t salen){
    char portstr[8];
    static char str[128];   /* Unix domain is largest */

    switch(sa->sa_family){
        case AF_INET: {
            struct sockaddr_in *sin = (struct sockaddr_in *) sa;

            if (NULL == inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str))){
                return NULL;
            }
            if (ntohs(sin->sin_port) != 0) {
                snprintf(portstr, sizeof(portstr), ":%d", ntohs(sin->sin_port));
                strcat(str, portstr);
            }
            return str;
        }
    }
    return NULL;
}
