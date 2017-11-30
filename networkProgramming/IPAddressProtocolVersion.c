#include <stdio.h>
#include <arpa/inet.h>

#define IPV4_ADDRESS    4
#define IPV6_ADDRESS    6
#define INVALID_IP_ADDRESS  -1

/*  This function validates the protocol version of the given string(IP Address)
 *  Input Params:
 *    ipAddress -  IPV4Address given by user in string format.
 *  Return value:
 *    4 - if the user input string is IPV4 Address.
 *    6 - If the user input string is IPV6 Address.
 *   -1 - If the user input string is not a valid IP Address.
 */
int ip_version(const char *ipAddress) 
{
    char nwAddrStruct[16];
    
    if (inet_pton(AF_INET, ipAddress, nwAddrStruct)) 
    {
        return IPV4_ADDRESS;
    }
    else if (inet_pton(AF_INET6, ipAddress, nwAddrStruct)) 
    {
        return IPV6_ADDRESS;
    }
    else
    {
        return INVALID_IP_ADDRESS;
    }
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

#if 0
127.0.0.1	 4
2300:c100::1:4	 6
fe80::ba2a:72ff:fefb:de4a	 6
2300:100::1:4	 6
raveendra	 -1
#endif
