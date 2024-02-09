CC = gcc
CFLAG = -c

OBJS = wrapsock.o wrappthread.o wrapunix.o

all: $(OBJS)

%.o: %.c
	$(CC) $^ $(CFLAG) -o $@

.PHONY: clean

clean: 
	rm -rf $(OBJS) liblib.a

pack:
	rm -rf liblib.a
	ar rcs liblib.a $(OBJS)