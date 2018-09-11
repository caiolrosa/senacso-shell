#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include "commands.h"

void pwd() {
    char* buffer;
    size_t bSize = 1024;
    printf("%s\n", getcwd(buffer, bSize));
}

void clear() {
    system("clear");
}

void ls(char* path) {
    struct dirent *dirEntry;

    DIR *directory = opendir(path);
    if (directory == NULL) {
        printf("Unable to list specified directory.\n");
        return;
    }

    while ((dirEntry = readdir(directory)) != NULL) { printf("%s\n", dirEntry->d_name); }
    closedir(directory);
    return;
}

void cd(char* path) {
    if (chdir(path) == -1) {
        printf("Unable to change directory.\n");
        return;
    }
}
