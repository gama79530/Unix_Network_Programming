CC = gcc
CFLAGS =

PROGS = exercise3_3

all: $(PROGS)

# ./exercise3_3
exercise3_3: exercise3_3.o 

clean:
	rm -rf $(PROGS) $(foreach prog, $(PROGS), $(prog).o) $(foreach prog, $(PROGS), $(prog).out)