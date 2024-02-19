CC = gcc
CFLAGS = -I../lib
LIBS = -static -L../lib -llib

PROGS = tcpserv01 tcpcli01 tcpserv02 tcpserv03 tcpcli04 tcpserv04 tcpcli11 tcpserv08 tcpcli08 tcpcli09 tcpserv09
OBJS = sigchldwait.o sigchldwaitpid.o str_cli11.o str_echo08.o str_cli08.o str_cli09.o str_echo09.o

all: $(PROGS) $(OBJS)


tcpcli09: tcpcli09.c str_cli09.o
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

tcpserv09: tcpserv09.c sigchldwaitpid.o str_echo09.o
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

str_echo09.o: str_echo09.c
	$(CC) $^ $(CFLAGS) -c -o $@

str_cli09.o: str_cli09.c
	$(CC) $^ $(CFLAGS) -c -o $@

str_cli08.o: str_cli08.c
	$(CC) $^ $(CFLAGS) -c -o $@

tcpcli08: tcpcli08.c str_cli08.o
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

tcpserv08: tcpserv08.c sigchldwaitpid.o str_echo08.o
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

str_echo08.o: str_echo08.c
	$(CC) $^ $(CFLAGS) -c -o $@

tcpcli11: tcpcli11.c str_cli11.o
	$(CC) $^ $(CFLAGS) $(LIBS) -o $@

str_cli11.o: str_cli11.c
	$(CC) $^ $(CFLAGS) -c -o $@

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