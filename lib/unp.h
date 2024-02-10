#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

#define	MAXLINE 4096    /* max text line length */
#define	SA struct sockaddr
#define	LISTENQ	1024    /* 2nd argument to listen() */

// wrapsock.c
int Socket(int family, int type, int protocol);
void Bind(int fd, const SA *sa, socklen_t salen);
void Listen(int fd, int backlog);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
// wrapunix.c
void Close(int fd);
void Write(int fd, void *ptr, size_t nbytes);
// sock_ntop.c
char* sock_ntop(const SA *sa, socklen_t salen);
// readn.c
ssize_t readn(int fd, void *vptr, size_t n);
// readline.c
static ssize_t my_read(int fd, char *ptr);
ssize_t readline(int fd, void *vptr, size_t maxlen);
ssize_t readlinebuf(void **vptrptr);
