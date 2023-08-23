#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void exec(char **argv);
char *instruct_location(char *instruct);
void exit(int status);
int stat(const char *pathname, struct stat *statbuf);

#endif
