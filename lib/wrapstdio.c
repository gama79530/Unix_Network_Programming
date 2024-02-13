#include	"unp.h"

char *Fgets(char *ptr, int n, FILE *stream){
    char *rptr = NULL;
    if (NULL == (rptr = fgets(ptr, n, stream)) && ferror(stream)){
        perror("fgets error");
        return rptr;
    }
    return rptr;
}

void Fputs(const char *ptr, FILE *stream){
    if(EOF == fputs(ptr, stream)){
        perror("fputs error");
        exit(EXIT_FAILURE);
    }
}

