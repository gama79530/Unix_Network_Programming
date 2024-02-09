#include "unp.h"
#include <pthread.h>

/* sec 1.4, fig 1-8, page 12 */
void Pthread_mutex_lock(pthread_mutex_t *mptr){
    int	n = 0;

    if (0 == (n = pthread_mutex_lock(mptr))){
        return;
    }
    errno = n;
    perror("pthread_mutex_lock error");
}