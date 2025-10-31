# system-calls

## info
Implemented by documentation on man7.org
- clock_gettime to read current time as struct
- get total nanoseconds by multiplying seconds by 1e9 and adding nanoseconds in current second
- gethostname simply reads in the hostname into a char array
- uname gets information about the current operating system
- sysinfo gets information about system state (only memory was used in this case)

## pinfo
Gets process info using system calls
- parsed a pid from input args using atoi or gets current process with getpid
- getpriority will fetch the priority of a process by its pid
  - The larger the number the higher priority it has
- Using sched_getscheduler we can get a process scheduler state using its pid

## pmod
Just remove 10 from the processes current priority, then sleep for an amount of time

## finfo
Get info about a file
- Most file systems store a lot of extra metadata about a file
- Using stat, this info can be collected into a stat struct
- First, check what type of record it is
  - Most modern file systems allow for many different types a record can be
  - In linux, almost everything is a "file" so the selection is even greater
- Next run through the permission flags of the file
- Check read, write, and execute for
  - User
  - Group
  - and other
