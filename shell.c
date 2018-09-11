#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands/commands.h"
#include "utils.h"

#define true 1
#define false 0

char* cmd;

void init() {
    cmd = malloc(sizeof(char));
    printf("Running our shell!!!\n");
}

void loop() {
    while(true) {
        printMessage();
        cmd = readLine();
        char** cmdArray = splitString(cmd, " ");
        if (cmdArray == NULL) { continue; }
        if (strcmp(cmdArray[0], "ls") == 0 ) { ls(cmdArray[1]); }
        if (strcmp(cmdArray[0], "cd") == 0 ) { cd(cmdArray[1]); }
        if (strcmp(cmdArray[0], "pwd") == 0) { printf(""); pwd(); }
        if (strcmp(cmdArray[0], "clear") == 0) { clear(); }
        free(cmdArray);
        free(cmd);
    }
}

void cleanup() {
    free(cmd);
}

int main(void) {
    init();
    loop();
    cleanup();
}
