/* Benjamin Jankowski
 * Lab 9
 * info.c
 */
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>

int main(int argc, char* argv[])
{
    struct timespec current_time;
    // https://man7.org/linux/man-pages/man2/clock_gettime.2.html
    clock_gettime(CLOCK_REALTIME, &current_time);
    long long elapsed_time = (current_time.tv_sec * 1e9) + current_time.tv_nsec;
    printf("Time in nanoseconds: %ld\n", elapsed_time);

    char hostname[256];
    // https://man7.org/linux/man-pages/man2/gethostname.2.html
    gethostname(hostname, sizeof(hostname));
    printf("System network hostname: %s\n", hostname);

    struct utsname uname_data;
    // https://man7.org/linux/man-pages/man2/uname.2.html
    if (uname(&uname_data) == 0) {
        printf("OS name: %s\n", uname_data.sysname);
        printf("OS release: %s\n", uname_data.release);
        printf("OS version: %s\n", uname_data.version);
        printf("Hardware type: %s\n", uname_data.machine);
    }

    printf("Numer of CPUs: %d\n", get_nprocs());

    struct sysinfo system_info;
    // https://man7.org/linux/man-pages/man2/sysinfo.2.html
    if (sysinfo(&system_info) == 0) {
        printf("Total memory: %lu\n", system_info.totalram);
        printf("Total free memory: %lu\n", system_info.freeram);
    }

    return 0;
}