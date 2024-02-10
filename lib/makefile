CC = gcc
CFLAG = -c

OBJS = wrapsock.o wrappthread.o wrapunix.o sock_ntop.o readn.o writen.o readline.o wraplib.o sockfd_to_family.o

all: $(OBJS)

%.o: %.c
	$(CC) $^ $(CFLAG) -o $@

.PHONY: clean

clean: 
	rm -rf $(OBJS) liblib.a

pack:
	rm -rf liblib.a
	ar rcs liblib.a $(OBJS)