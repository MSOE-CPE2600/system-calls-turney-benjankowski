/* Benjamin Jankowski
 * Lab 9
 * pinfo.c
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int pid;

    if (argc > 1) {
        pid = atoi(argv[1]);
    } else {
        // https://man7.org/linux/man-pages/man2/getpid.2.html
        pid = getpid();
    }

    // https://man7.org/linux/man-pages/man2/setpriority.2.html
    int priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1) {
        printf("Unable to get process priority\n");
    } else {
        printf("Process priority: %d\n", priority);
    }

    // https://man7.org/linux/man-pages/man2/sched_setscheduler.2.html
    int scheduler = sched_getscheduler(pid);
    if (scheduler == -1) {
        printf("Unable to get scheduler information\n");
    } else {
        printf("Scheduler Mode: ");
        switch (scheduler) {
            case SCHED_OTHER:
                printf("Other\n");
                break;
            case SCHED_FIFO:
                printf("FIFO\n");
                break;
            case SCHED_RR:
                printf("RR\n");
                break;
            case SCHED_BATCH:
                printf("Batch\n");
                break;
            case SCHED_IDLE:
                printf("Idle\n");
                break;
            default:
                printf("Unknown\n");
                break;
        }
    }

    return 0;
}