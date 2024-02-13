#include "unp.h"

static int	read_cnt;
static char	*read_ptr;
static char	read_buf[MAXLINE];

/* sec 3.9, fig 3-18, page 74 */
static ssize_t my_read(int fd, char *ptr){
    if(0 >= read_cnt){
    again:
        if(0 > (read_cnt = read(fd, read_buf, sizeof(read_buf)))){
            if(errno == EINTR){
                goto again;
            }
            return -1;
        }else if(0 == read_cnt){
            return 0;
        }
        read_ptr = read_buf;
    }

    read_cnt--;
    *ptr = *read_ptr++;
    return 1;
}

/* sec 3.9, fig 3-18, page 74 */
ssize_t readline(int fd, void *vptr, size_t maxlen){
    ssize_t	n, rc;
    char c, *ptr;
    ptr = vptr;

    for(n = 1; n < maxlen; n++){
        if(1 == (rc = my_read(fd, &c))){
            *ptr++ = c;
            if(c == '\n'){
                break;  /* newline is stored, like fgets() */
            }
        }else if(0 == rc){
            *ptr = 0;
            return n - 1;   /* EOF, n - 1 bytes were read */
        }else{
            return -1;  /* error, errno set by read() */
        }
    }

    *ptr = 0;   /* null terminate like fgets() */
    return n;
}

/* sec 3.9, fig 3-18, page 74 */
ssize_t readlinebuf(void **vptrptr){
    if(read_cnt){
        *vptrptr = read_ptr;
    }
    return read_cnt;
}

ssize_t Readline(int fd, void *ptr, size_t maxlen){
    ssize_t n;
    if (0 > (n = readline(fd, ptr, maxlen))){
        perror("readline error");
        exit(EXIT_FAILURE);
    }
    return n;
}
