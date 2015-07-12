/**
*@Author: Raveendra Reddy Padala
*@Version:0.1
*@
*@brief:
**/
#if 0
limits.h
CHAR_BIT   = number of bits in a char
SCHAR_MIN  = minimum value for a signed char
SCHAR_MAX  = maximum value for a signed char
UCHAR_MAX  = maximum value for an unsigned char
CHAR_MIN   = minimum value for a char
CHAR_MAX   = maximum value for a char
MB_LEN_MAX = maximum multibyte length of a character accross locales
SHRT_MIN   = minimum value for a short
SHRT_MAX   = maximum value for a short
USHRT_MAX  = maximum value for an unsigned short
INT_MIN    = minimum value for an int
INT_MAX    = maximum value for an int
UINT_MAX   = maximum value for an unsigned int
LONG_MIN   = minimum value for a long
LONG_MAX   = maximum value for a long
ULONG_MAX  = maximum value for an unsigned long
LLONG_MIN  = minimum value for a long long
LLONG_MAX  = maximum value for a long long
ULLONG_MAX = maximum value for an unsigned long long
float.h
FLT_MIN  = min value of a float
FLT_MAX  = max value of a float
DBL_MIN  = min value of a double
DBL_MAX  = max value of a double
LDBL_MIN = min value of a long double
LDBL_MAX = max value of a long double
#endif

#include<stdio.h>
#include<limits.h>

#define umaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
					 (0xFULL << ((sizeof(t) * 8ULL) - 4ULL)))

#define smaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
					 (0x7ULL << ((sizeof(t) * 8ULL) - 4ULL)))
char *arrOfChar[][2]={
		  "No. of Bits in char", "CHAR_BIT",
		  "Minimum Value of Signed char is ", "SCHAR_MIN"
};
int main(int argc, char** argv) {
		  int i=0;
		  printf("schar: %llx uchar: %llx\n", smaxof(char), umaxof(char));
		  printf("sshort: %llx ushort: %llx\n", smaxof(short),
								umaxof(short));
		  printf("sint: %llx uint: %llx\n", smaxof(int), umaxof(int));
		  printf("slong: %llx ulong: %llx\n", smaxof(long),
								umaxof(long));
		  printf("slong long: %llx ulong long: %llx\n",
								smaxof(long long),
								umaxof(long long));
		  //Macros In Limits.h		  
		  printf("No.Of Bits in Char %d\n", CHAR_BIT);
		  printf("Minimum Value of Signed Char is %d\n",SCHAR_MIN);
		  printf("Maximum Value of Signed Char is %d\n",SCHAR_MAX);
		  printf("Maximum Value of Unsigned Char is %d\n",UCHAR_MAX);
		  printf("Minimum Value of Char is %d\n",CHAR_MIN);
		  printf("Maxmum Value of Char is %d\n",CHAR_MAX);

		  printf("Maximum value of INT 	%d\n",INT_MAX);
for(i=0;i<1;i++)
{
		  printf("%s:%d\n",arrOfChar[i][i],arrOfChar[i][++i]);
}
		  return 0;
}
