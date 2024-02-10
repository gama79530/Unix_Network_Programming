#include "unp.h"

#define CPU_VENDOR_OS "Intel(R) Core(TM) i7-6700HQ CPU"

/* sec 3.4, fig 3-10, page 64 */
int main(int argc, char **argv){
    union {
      short  s;
      char   c[sizeof(short)];
    } un;

    un.s = 0x0102;
    printf("%s: ", CPU_VENDOR_OS);
    if(sizeof(short) == 2){
        if(un.c[0] == 1 && un.c[1] == 2){
            printf("big-endian\n");
        }else if (un.c[0] == 2 && un.c[1] == 1){
            printf("little-endian\n");
        }else{
            printf("unknown\n");
        }
    }else{
        printf("sizeof(short) = %ld\n", sizeof(short));
    }

    exit(0);
}
