#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define INET_PTON_SUCCESS 1

/*  This function validates the IPV6 Address
 *  Input Params:
 *    pIPV6Address -  IPV6Address given by user in string format.
 *  Return value:
 *    false - if the user input string is NOT valid IPV6 Address.
 *    true - If the user input string is valid IPV6 Address.
 */
bool ValidateIPV6Address(const char *pIPV6Address)
{
   signed int status = 0;
   bool returnStatus = false;
   unsigned char buf[sizeof(struct in6_addr)] = {0};
   
   //string has some data
   status = inet_pton(AF_INET6, pIPV6Address, buf);
   printf("%s::%d inet_pton AF_INET for %s returned %d\n", __FUNCTION__, __LINE__, pIPV6Address, status);

   if (INET_PTON_SUCCESS == status)
   {
      printf("%s::%d IPV6 Address is valid\n", __FUNCTION__, __LINE__ );
      returnStatus = true;
   }
   //validation failed, so return false
   else
     printf("%s::%d IPV6 Address is INVALID\n", __FUNCTION__, __LINE__);

   return returnStatus;
 }

int main(void)
{
   bool status = false;
   //Negative Test Cases
   status = ValidateIPV6Address("2300:c100::1:4");
   printf("status should be false:%d\n",status);
   status = ValidateIPV6Address("fe80::ba2a:72ff:fefb:de4a");
   printf("status should be false:%d\n",status);
   status = ValidateIPV6Address("2300:100::1:4");
   printf("status should be false:%d\n",status);
   status = ValidateIPV6Address("Raveendra");
   printf("status should be false:%d\n",status);
   status = ValidateIPV6Address("255.255.255.256");
   printf("status should be false:%d\n",status);
   
   // Positive Test Cases
   status = ValidateIPV6Address("255.255.255.255");
   printf("status should be true:%d\n",status);
   status = ValidateIPV6Address("127.0.0.1");
   printf("status should be true:%d\n",status);
   status = ValidateIPV6Address("0.0.0.0");
   printf("status should be true:%d\n",status);
   return 0;

}

#if 0
OUTPUT:
ValidateIPV6Address::24 inet_pton AF_INET for 2300:c100::1:4 returned 1
ValidateIPV6Address::28 IPV6 Address is valid
status should be false:1
ValidateIPV6Address::24 inet_pton AF_INET for fe80::ba2a:72ff:fefb:de4a returned 1
ValidateIPV6Address::28 IPV6 Address is valid
status should be false:1
ValidateIPV6Address::24 inet_pton AF_INET for 2300:100::1:4 returned 1
ValidateIPV6Address::28 IPV6 Address is valid
status should be false:1
ValidateIPV6Address::24 inet_pton AF_INET for Raveendra returned 0
ValidateIPV6Address::33 IPV6 Address is INVALID
status should be false:0
ValidateIPV6Address::24 inet_pton AF_INET for 255.255.255.256 returned 0
ValidateIPV6Address::33 IPV6 Address is INVALID
status should be false:0
ValidateIPV6Address::24 inet_pton AF_INET for 255.255.255.255 returned 0
ValidateIPV6Address::33 IPV6 Address is INVALID
status should be true:0
ValidateIPV6Address::24 inet_pton AF_INET for 127.0.0.1 returned 0
ValidateIPV6Address::33 IPV6 Address is INVALID
status should be true:0
ValidateIPV6Address::24 inet_pton AF_INET for 0.0.0.0 returned 0
ValidateIPV6Address::33 IPV6 Address is INVALID
status should be true:0
#endif
