#include <stdio.h>
#include<string.h>
#include <time.h>

#define LEN 32

int parseTime(char * buf);

int main ()
{
   char buf[LEN] ="";

   printf("Sending Proper Date\n");
   strncpy(buf,"2018-8-12T13:35:20",32);
   parseTime(buf);

   printf("Sending invalid month >12 \n");
   strncpy(buf,"2018-13-12T13:35:20",32);
   parseTime(buf);

   printf("Sending invalid month=0\n");
   strncpy(buf,"2000-0-12T13:35:20",32);
   parseTime(buf);

   printf("Sending invalid Date=0\n");
   strncpy(buf,"2000-8-0T13:35:20",32);
   parseTime(buf);

   printf("Sending Invalid Separator\n");
   strncpy(buf,"2000-8-12X13:35:20",32);
   parseTime(buf); 

   printf("Sending Invalid Hour >24 \n");
   strncpy(buf,"2000-8-12X26:35:20",32);
   parseTime(buf); 

   printf("Sending Invalid Minutes>60 \n");
   strncpy(buf,"2000-8-12X13:65:20",32);
   parseTime(buf); 

   printf("Sending Invalid Seconds>60 \n");
   strncpy(buf,"2000-8-12X13:65:80",32);
   parseTime(buf); 

}
/*
 * This will parse the date and time
*/
 int parseTime(char * buf)
 { 
    struct tm tm = {0};
    char *s = strptime(buf, "%Y-%m-%dT%H:%M:%S", &tm);
    if (s == NULL)
    {
        printf("Cannot parse date"); 
        return 0;
    }
    //Print Date
    printf("year: %d; month: %d; day: %d;\n",
                 tm.tm_year + 1900, (tm.tm_mon+1), tm.tm_mday);
   //Print Time
    printf("hour: %d; minute: %d; second: %d\n",
                 tm.tm_hour, tm.tm_min, tm.tm_sec);

    printf("week day: %d; year day: %d\n", tm.tm_wday, tm.tm_yday);

   return 1;
}
