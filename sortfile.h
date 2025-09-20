#ifndef SORTFILE
#define SORTFILE

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>


#define INPUT_FILENAME "onegin.txt"
#define OUTPUT_FILENAME_START "onegin_startsort.txt"
#define OUTPUT_FILENAME_END "onegin_endsort.txt"
#define FROM_START 0
#define FROM_END 1

int bubble_sort(bool mode, char*** adr_adr, int num_str);

int my_strcmp(bool mode, char* a, char* b);

#endif