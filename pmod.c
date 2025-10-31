/* Benjamin Jankowski
 * Lab 9
 * pmod.c
 */
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char* argv[])
{
    nice(10); // https://www.man7.org/linux/man-pages/man2/nice.2.html

    struct timespec sleep_time = {1, 837272638};
    nanosleep(&sleep_time, NULL); // https://man7.org/linux/man-pages/man2/nanosleep.2.html

    printf("Goodbye\n");
    return 0;
}