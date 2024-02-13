#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

#define	MAXLINE 4096    /* max text line length */
#define	SA struct sockaddr
#define	LISTENQ	1024    /* 2nd argument to listen() */
#define SERV_PORT 9877

typedef	void Sigfunc(int);  /* for signal handlers */

// wrapsock.c
int Socket(int family, int type, int protocol);
void Bind(int fd, const SA *sa, socklen_t salen);
void Listen(int fd, int backlog);
int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
void Connect(int fd, const SA *sa, socklen_t salen);
// wrapunix.c
void Close(int fd);
void Write(int fd, void *ptr, size_t nbytes);
pid_t Fork(void);
// sock_ntop.c
char* sock_ntop(const SA *sa, socklen_t salen);
// readn.c
ssize_t readn(int fd, void *vptr, size_t n);
// readline.c
static ssize_t my_read(int fd, char *ptr);
ssize_t readline(int fd, void *vptr, size_t maxlen);
ssize_t readlinebuf(void **vptrptr);
ssize_t Readline(int fd, void *ptr, size_t maxlen);
// wraplib.c
const char *Inet_ntop(int family, const void *addrptr, char *strptr, size_t len);
void Inet_pton(int family, const char *strptr, void *addrptr);
// sockfd_to_family.c
int sockfd_to_family(int sockfd);
// str_echo.c
void str_echo(int sockfd);
// writen.c
ssize_t writen(int fd, const void *vptr, size_t n);
void Writen(int fd, void *ptr, size_t nbytes);
// wrapstdio.c
char *Fgets(char *ptr, int n, FILE *stream);
void Fputs(const char *ptr, FILE *stream);
// str_cli.c
void str_cli(FILE *fp, int sockfd);
// signal.c
Sigfunc *signal(int signo, Sigfunc *func);
Sigfunc *Signal(int signo, Sigfunc *func);