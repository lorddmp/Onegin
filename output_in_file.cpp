#include "output_in_file.h"

int output_in_file(const char* filename, char** adr_adr, int num_str)
{
    FILE* fpp = fopen(filename, "w");

    if (fpp == NULL)
    {
        printf("Error");
        return 1;
    }
    
    for (int i = 0; i < num_str; i++)
        fputs(*(adr_adr + i), fpp);
    
    return 0;
}
