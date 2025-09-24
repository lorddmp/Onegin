#ifndef WORK_WITH_FILE
#define WORK_WITH_FILE

#include <stdio.h>
#include "structure.h"

int work_with_file(FILE* fp, struct stat* buf, char** ptr_buffer, char** adr_n, int* num_str);

struct_string_and_strlen** massive_address(struct_string_and_strlen** ptr_struct, char* ptr_buffer, char** adr_n, int num_str);

#endif