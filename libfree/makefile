CC = gcc
CFLAG = -c

OBJS = inet_pton_ipv4.o inet_ntop_ipv4.o

all: $(OBJS)

%.o: %.c
	$(CC) $^ $(CFLAG) -o $@

.PHONY: clean

clean: 
	rm -rf $(OBJS) 

pack:
	ar rcs $(OBJS)