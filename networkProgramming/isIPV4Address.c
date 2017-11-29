#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define INET_PTON_SUCCESS 1

/*  This function validates the IPV4 Address
 *  Input Params:
 *    pIPV4Address -  IPV4Address given by user in string format.
 *  Return value:
 *    false - if the user input string is NOT valid IPV4 Address.
 *    true - If the user input string is valid IPV4 Address.
 */
bool ValidateIPV4Address(const char *pIPV4Address)
{
   signed int status = 0;
   bool returnStatus = false;
   unsigned char buf[sizeof(struct in6_addr)] = {0};
   
   //string has some data
   status = inet_pton(AF_INET, pIPV4Address, buf);
   printf("%s::%d inet_pton AF_INET for %s returned %d\n", __FUNCTION__, __LINE__, pIPV4Address, status);

   if (INET_PTON_SUCCESS == status)
   {
      printf("%s::%d IPV4 Address is valid\n", __FUNCTION__, __LINE__ );
      returnStatus = true;
   }
   //validation failed, so return false
   else
     printf("%s::%d IPV4 Address is INVALID\n", __FUNCTION__, __LINE__);

   return returnStatus;
 }

int main(void)
{
   bool status = false;
   status = ValidateIPV4Address("2300:c100::1:4");
   printf("status should be false:%d\n",status);
   status = ValidateIPV4Address("fe80::ba2a:72ff:fefb:de4a");
   printf("status should be false:%d\n",status);
   status = ValidateIPV4Address("2300:100::1:4");
   printf("status should be false:%d\n",status);
   status = ValidateIPV4Address("127.0.0.1");
   printf("status should be true:%d\n",status);

   return 0;

}

#if 0
OUTPUT:
ValidateIPV4Address::26 inet_pton AF_INET for 2300:c100::1:4 returned 0
ValidateIPV4Address::35 IPV4 Address is INVALID
status should be false:0
ValidateIPV4Address::26 inet_pton AF_INET for fe80::ba2a:72ff:fefb:de4a returned 0
ValidateIPV4Address::35 IPV4 Address is INVALID
status should be false:0
ValidateIPV4Address::26 inet_pton AF_INET for 2300:100::1:4 returned 0
ValidateIPV4Address::35 IPV4 Address is INVALID
status should be false:0
ValidateIPV4Address::26 inet_pton AF_INET for 127.0.0.1 returned 1
ValidateIPV4Address::30 IPV4 Address is valid
status should be true:1
#endif
