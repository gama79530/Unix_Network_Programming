#include <stdio.h>
#include <arpa/inet.h>

/* exercise 3.3, page 76 */
int inet_pton_loose(int af, const char *restrict src, void *restrict dst);

int inet_pton_loose(int af, const char *restrict src, void *restrict dst){
    int ret_val;
    if(0 != (ret_val = inet_pton(af, src, dst))){
        return ret_val;
    }
    
    return inet_aton(src, (struct in_addr *)dst);
}

int main(void){
    const char *src_v4 = "255.255.0xffff";
    const char *src_v6 = "::ffff:255.255.255.255";
    int ret_val;
    uint32_t dst;

    ret_val = inet_pton_loose(AF_INET, src_v4, &dst);
    printf("inet_pton_loose return %d (input: %s)\n", ret_val, src_v4);
    if(ret_val == 1){
        printf("The binary address is %u\n", dst);
    }
    printf("\n");

    ret_val = inet_pton(AF_INET, src_v4, &dst);
    printf("inet_pton return %d (input: %s)\n", ret_val, src_v4);
    if(ret_val == 1){
        printf("the binary address is %u\n", dst);
    }

    printf("\n");
    ret_val = inet_pton_loose(AF_INET6, src_v6, &dst);
    printf("inet_pton_loose return %d (input: %s)\n", ret_val, src_v6);
    if(ret_val == 1){
        printf("The binary address is %u\n", dst);
    }
    printf("\n");

    ret_val = inet_pton(AF_INET6, src_v6, &dst);
    printf("inet_pton return %d (input: %s)\n", ret_val, src_v6);
    if(ret_val == 1){
        printf("the binary address is %u\n", dst);
    }

    return 0;
}