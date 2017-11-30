#include <arpa/inet.h>
#include <stdio.h>

static int
ip_version(const char *src) {
    char buf[16];
    if (inet_pton(AF_INET, src, buf)) {
        return 4;
    } else if (inet_pton(AF_INET6, src, buf)) {
        return 6;
    }
    return -1;
}

int
main(void ) {
    
    //Postive Test Case
    printf("127.0.0.1\t %d\n",ip_version("127.0.0.1"));
    printf("2300:c100::1:4\t %d\n",ip_version("2300:c100::1:4"));
    printf("fe80::ba2a:72ff:fefb:de4a\t %d\n",ip_version("fe80::ba2a:72ff:fefb:de4a"));
    printf("2300:100::1:4\t %d\n",ip_version("2300:100::1:4"));
    
    //Negative Test Case
    printf("raveendra\t %d\n",ip_version("raveendra"));
    
    return 0;
}
