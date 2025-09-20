#ifndef WORK_WITH_FILE
#define WORK_WITH_FILE

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

int work_with_file(FILE** fp, struct stat* buf, char** ptr_buffer, char** adr_n, int* num_str);

int massive_address(char*** adr_adr, char* ptr_buffer, char** adr_n, int num_str);

#endif