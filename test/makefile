CC = gcc
CFLAGS = -c -I../lib

OBJS = readline1.o

all: $(OBJS)

%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY: clean

clean: 
	rm -rf $(OBJS)