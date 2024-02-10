#include "unp.h"

/* sec 3.9, fig 1-17, page 73 */
ssize_t readline(int fd, void *vptr, size_t maxlen){
    ssize_t n = 0, rc = 0;
    char c, *ptr = NULL;

    ptr = vptr;
    for(n = 1; n < maxlen; n++){
    again:
        if(1 == (rc = read(fd, &c, 1))){
            *ptr++ = c;
            if('\n' == c){
                break;
            }
        }else if(0 == rc){
            *ptr = '\0';
            return n-1;
        }else{
            if(EINTR == errno){
                goto again;
            }
            return -1;
        }
    }

    *ptr = '\0';
    return n;
}