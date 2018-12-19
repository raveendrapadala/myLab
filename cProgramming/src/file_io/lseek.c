/*
* DESCRIPTION: Tests standard input to see whether it's capable of seeking 
*/
#include <unistd.h>

int main (void)
{
  /* check whether stdin is able to seek or not? */
  if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    printf("cannot seek\n");
  else
    printf("seek OK\n");
  
  exit(0);
}

/*************************************
Output:
$ ./a.out < /etc/passwd
seek OK
$ cat < /etc/passwd | ./a.out
cannot seek
$ ./a.out < /var/spool/cron/FIFO
cannot seek
**************************************/
