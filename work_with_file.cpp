#include "work_with_file.h"

int work_with_file(FILE** fp, struct stat* buf, char** ptr_buffer, char** adr_n, int* num_str)
{
    *ptr_buffer = (char*)calloc(buf->st_size + 1, sizeof(char));
    if (ptr_buffer == NULL)
    {
        printf("Error in calloc\n");
        return 1;
    }
    
    fread(*ptr_buffer, sizeof(char), buf->st_size, *fp);
    *adr_n = *ptr_buffer;
    while (1)
    {
        *adr_n = strchr(*adr_n, '\n');
        (*num_str)++;

        if (*adr_n == NULL)
            break;
        
        **adr_n = '\0';
        (*adr_n)++;
    }
    *adr_n = *ptr_buffer;
    return 0;
}

int massive_address(char*** adr_adr, char* ptr_buffer, char** adr_n, int num_str)
{
    *adr_adr = (char**) calloc((size_t) num_str, sizeof(char*));

    if ((*adr_adr) == NULL)
    {
        printf("ERROR CALLOC");
        return 1;
    }

    **adr_adr = ptr_buffer;

    for (int i = 1; i < num_str; i++)
    {
        (*adr_n) = strchr(*adr_n, '\0');
        if ((*adr_n) == NULL)
            break;
        
        
        (*adr_n)++;
        *((*adr_adr) + i) = *adr_n;
        
    }

    return 0;
}

