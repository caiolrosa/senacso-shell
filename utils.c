#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utils.h"
#include "pwd.h"

char** splitString(char* str, char* sep) {
    if (str[0] == '\0') { return NULL; }
    size_t count = 1;
    while(1) { 
        if (str[count] == '\0') { break; }
        count++;
    }
    count--;

    size_t splitPos = 0;
    char* token;
    char* buffer = strdup(str);
    char** splitArr = malloc(sizeof(char) * count);
    while ((token = strsep(&buffer, " ")) != NULL) {
        splitArr[splitPos] = token;
        splitPos++;
    }
    
    return splitArr;
}

char* readLine() {
    char *input = NULL;
    size_t buffer = 0;
    getline(&input, &buffer, stdin);
    if (input[strlen(input) - 1] == '\n') { input[strlen(input) - 1] = '\0'; }
    return input;
}

void printMessage() {    
    printf("shell >> ");
}