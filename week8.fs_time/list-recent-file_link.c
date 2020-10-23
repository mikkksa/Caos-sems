#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>


int main(int argc, char *argv[])
{
    const char * dir_path = argv[1];
    int year = strtol(argv[2], NULL, 10);
    int mon = strtol(argv[3], NULL, 10);
    int day = strtol(argv[4], NULL, 10);
    int dirfd = open(dir_path, O_RDONLY | O_DIRECTORY);
    DIR *dir = fdopendir(dirfd);

    struct dirent *entry;
    struct stat st;
    struct tm max_tm;

    memset(&max_tm, 0, sizeof(max_tm));
    max_tm.tm_year = year - 1900;
    max_tm.tm_mon = mon - 1;
    max_tm.tm_mday = day;
    max_tm.tm_isdst = -1;
    time_t max_time = mktime(&max_tm);

    while ((entry=readdir(dir))) {
        fstatat(dirfd, entry->d_name, &st, 0);
        time_t modified = st.st_mtime;
        if (modified >= max_time) {
            printf("%s\n", entry->d_name);
        }
    }        
    closedir(dir);
}
