/* Benjamin Jankowski
 * Lab 9
 * finfo.c
 */
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

#define PRINT_PERM_BIT(perm_flag, c) printf((file_state.st_mode & perm_flag) ? (c) : "-")

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    struct stat file_state;
    // https://man7.org/linux/man-pages/man2/stat.2.html
    if (stat(argv[1], &file_state) == -1) {
        printf("Failed to read file stats\n");
        return 1;
    }

    printf("File Type: ");
    switch (file_state.st_mode & S_IFMT) {
        case S_IFBLK: printf("Block device\n"); break;
        case S_IFCHR: printf("Character device\n"); break;
        case S_IFDIR: printf("Directory\n"); break;
        case S_IFIFO: printf("FIFO\n"); break;
        case S_IFLNK: printf("Symlink\n"); break;
        case S_IFREG: printf("File\n"); break;
        case S_IFSOCK: printf("Socket\n"); break;
        default: printf("Unknown file");
    }

    printf("Permissions: ");
    printf(S_ISDIR(file_state.st_mode)  ? "d" : "-");
    PRINT_PERM_BIT(S_IRUSR, "r");
    PRINT_PERM_BIT(S_IWUSR, "w");
    PRINT_PERM_BIT(S_IXUSR, "x");
    PRINT_PERM_BIT(S_IRGRP, "r");
    PRINT_PERM_BIT(S_IWGRP, "w");
    PRINT_PERM_BIT(S_IXGRP, "x");
    PRINT_PERM_BIT(S_IROTH, "r");
    PRINT_PERM_BIT(S_IWOTH, "w");
    PRINT_PERM_BIT(S_IXOTH, "x");
    printf("\n");

    printf("Owner ID: %d\n", file_state.st_uid);
    printf("File Size: %ld\n", file_state.st_size);

    char time_buffer[100];
    // https://man7.org/linux/man-pages/man3/strftime.3.html
    strftime(time_buffer,
        sizeof(time_buffer),
        "%b %d %Y %H:%M",
        localtime(&file_state.st_mtime));

    printf("Last changed: %s\n", time_buffer);

    return 0;
}