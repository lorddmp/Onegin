#ifndef SORTFILE
#define SORTFILE

#include <stdio.h>
#include "structure.h"

struct_string_and_strlen** bubble_sort_from_start(struct_string_and_strlen** adr_struct, int num_str);

struct_string_and_strlen** bubble_sort_from_end(struct_string_and_strlen** adr_struct, int num_str);

int my_strcmp_from_start(struct_string_and_strlen* a, struct_string_and_strlen* b);

int my_strcmp_from_end(struct_string_and_strlen* a, struct_string_and_strlen* b);

#endif