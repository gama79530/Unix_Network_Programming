CC = gcc
CFLAGS = -static -I../lib -L../lib -llib

PROGS = daytimetcpcli daytimetcpcliv6 daytimetcpsrv

all: $(PROGS)

# ./daytimetcpcli 128.138.140.44
daytimetcpcli: daytimetcpcli.c
	$(CC) $^ $(CFLAGS) -o $@

daytimetcpcliv6: daytimetcpcliv6.c
	$(CC) $^ $(CFLAGS) -o $@

daytimetcpsrv: daytimetcpsrv.c
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm -rf $(PROGS) $(foreach prog, $(PROGS), $(prog).o)