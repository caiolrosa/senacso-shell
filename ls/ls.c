#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include "ls.h"

void ls(char* path) {
    struct dirent **dirEntry;
    int dirSize = scandir(path, &dirEntry, 0, alphasort);

    if (dirSize >= 0) {
        int i;
        for (i = 0; i < dirSize; i++) {
            printf("COUNT: %d", i);
            printf("%s\n", dirEntry[i]->d_name);
        }
    } else {
        printf("Could not execute ls command.");
    }

    printf("Leaving ls function");
}
