#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ls/ls.h"
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
        scanf("%[^\n]s", cmd);
        char** cmdArray = splitString(cmd, " ");
        if (cmdArray == NULL) { continue; }
        if (strcmp(cmdArray[0], "ls") == 0) { ls(cmdArray[1]); cmd = ""; }
        printf("Finished executing");
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
