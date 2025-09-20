#ifndef OPEN_FILE
#define OPENFILE

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

#define INPUT_FILENAME "onegin.txt"

int open_file(FILE** fp, struct stat* buf);

#endif