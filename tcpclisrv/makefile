CC = gcc
CFLAGS = -I../lib
LIBS = -static -L../lib -llib

PROGS = tcpserv01 tcpcli01 tcpserv02 tcpserv03 tcpcli04 tcpserv04
OBJS = sigchldwait.o sigchldwaitpid.o

all: $(PROGS) $(OBJS)

tcpserv04: tcpserv04.c sigchldwaitpid.o
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

sigchldwaitpid.o: sigchldwaitpid.c
	$(CC) $^ $(CFLAGS) -c -o $@

tcpcli04: tcpcli04.c
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

tcpserv03: tcpserv03.c sigchldwait.o
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

tcpserv02: tcpserv02.c sigchldwait.o
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

sigchldwait.o: sigchldwait.c
	$(CC) $^ $(CFLAGS) -c -o $@

tcpserv01: tcpserv01.c
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

tcpcli01: tcpcli01.c
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

clean:
	rm -rf $(PROGS) $(foreach prog, $(PROGS), $(prog).o) $(OBJS)