CC = gcc
CFLAGS = -c -static -I../lib -L../lib -llib

OBJS = readline1.o

all: $(OBJS)

%.o: %.c
	$(CC) $^ $(CFLAGS) -o $@

.PHONY: clean

clean: 
	rm -rf $(OBJS)