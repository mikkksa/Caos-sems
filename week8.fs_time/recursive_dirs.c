#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <limits.h>


static void
list_dir (const char * dir_name) {
    DIR *d = opendir (dir_name);

    if (!d) {
        fprintf (stderr, "Cannot open directory '%s': %s\n",
                 dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }
    while (1) {
        struct dirent *entry;
        const char *d_name;

        entry = readdir(d);
        if (!entry) {
            break;
        }
        d_name = entry->d_name;
	    printf ("%s/%s\n", dir_name, d_name);


        if (entry->d_type & DT_DIR) {
            if (!strcmp(d_name, ".") || !strcmp(d_name, "..")) {
                continue;
            }
            char path[256];
            memset(path, '\0', 256);
            strcat(path, dir_name);
            strcat(path, "/");
            strcat(path, d_name);
            list_dir(path);
	    }
    }

    if (closedir(d)) {
        fprintf (stderr, "Could not close '%s': %s\n",
                 dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }
}

int main () {
    list_dir ("/");
    return 0;
}
