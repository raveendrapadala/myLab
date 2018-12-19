#include "apue.h"
#include <fcntl.h>
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
int
main(void)
{
int fd;
if ((fd = creat("file.hole", FILE_MODE)) < 0)
err_sys("creat error");
if (write(fd, buf1, 10) != 10)
err_sys("buf1 write error");
/* offset now = 10 */
if (lseek(fd, 16384, SEEK_SET) == -1)
err_sys("lseek error");
/* offset now = 16384 */
if (write(fd, buf2, 10) != 10)
err_sys("buf2 write error");
/* offset now = 16394 */
exit(0);
}

/******************************************************************
Running this program gives us
$ ./a.out
$ ls -l file.hole check its size
-rw-r--r-- 1 sar 16394 Nov 25 01:01 file.hole
$ od -c file.hole let’s look at the actual contents
0000000 a b c d e f g h i j \0 \0 \0 \0 \0 \0
0000020 \0 \0 \0 \0 \0 \0 \0 \0 \0 \0 \0 \0 \0 \0 \0 \0
*
0040000 A B C D E F G H I J
0040012
*********************************************************************/
