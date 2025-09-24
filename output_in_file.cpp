#include "output_in_file.h"

#include <stdio.h>
#include <assert.h>

int output_in_file(const char* filename, struct_string_and_strlen** adr_struct, int num_str)
{
    assert(filename);
    assert(adr_struct);
    
    FILE* fpp = fopen(filename, "w");

    if (fpp == NULL)
    {
        printf("Error");
        return 1;
    }
    
    for (int i = 0; i < num_str; i++)
        fputs(adr_struct[i]->string, fpp);
    
    return 0;
}
