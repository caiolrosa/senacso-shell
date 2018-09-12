#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ftw.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "commands.h"
#define RWX_MODE 0700

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

    while ((dirEntry = readdir(directory)) != NULL) { 
        if (strcmp(dirEntry->d_name, ".") == 0 || strcmp(dirEntry->d_name, "..") == 0) { continue; }
        printf("%s\n", dirEntry->d_name); 
    }
    closedir(directory);
    return;
}

void cd(char* path) {
    if (chdir(path) == -1) {
        printf("Unable to change directory.\n");
        return;
    }
}

void createDirectory(char* path) {
    struct stat st = { 0 };
    if (stat(path, &st) == -1) {
        mkdir(path, RWX_MODE);
    }
}

void rm(char* path) {
    struct stat st = { 0 };
    if (stat(path, &st) == 0) {
        remove(path);
    }
}

static int rmrf_func(const char* path, const struct stat *sb, int typeFlag, struct FTW *ftwbuf) { return remove(path); }
void rmf(char* path) {
    struct stat st = { 0 };
    if (stat(path, &st) == 0) {
        nftw(path, rmrf_func, 64, FTW_DEPTH|FTW_MOUNT|FTW_PHYS);
    }
}

void touch(char* path) {
    FILE *file = fopen(path, "w");
    if (!file) { printf("Unable to create file."); return; }
    fclose(file);
}