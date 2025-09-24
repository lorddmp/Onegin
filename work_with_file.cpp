#include "work_with_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <assert.h>

int work_with_file(FILE* fp, struct stat* buf, char** ptr_buffer, char** adr_n, int* num_str)
{
    assert(&fp);
    assert(buf);

    char* ptr_buffer_func = *ptr_buffer;
    char* adr_n_func = *adr_n;
    
    ptr_buffer_func = (char*)calloc((size_t)buf->st_size + 1, sizeof(char));
    if (ptr_buffer_func == NULL)
    {
        printf("Error in calloc\n");
        return 1;
    }
    
    fread(ptr_buffer_func, sizeof(char), (size_t)buf->st_size, fp);
    adr_n_func = ptr_buffer_func;
    while(1)
    {
        adr_n_func = strchr(adr_n_func, '\n');
        (*num_str)++;

        if (adr_n_func == NULL)
            break;
        
        *adr_n_func = '\0';
        (adr_n_func)++;
    }
    adr_n_func = ptr_buffer_func;

    *ptr_buffer = ptr_buffer_func;
    *adr_n = adr_n_func;
    
    return 0;
}

struct_string_and_strlen** massive_address(struct_string_and_strlen** ptr_struct, char* ptr_buffer, char** adr_n, int num_str)
{
    assert(ptr_buffer);
    assert(adr_n);

    char* adr_n_func = *adr_n;

    struct_string_and_strlen** adr_struct_func = 0;
    
    *ptr_struct = (struct_string_and_strlen*) calloc((size_t) num_str, sizeof(struct_string_and_strlen));
    adr_struct_func = (struct_string_and_strlen**) calloc((size_t) num_str, sizeof(struct_string_and_strlen*));

    if ((*ptr_struct) == NULL)
    {
        printf("ERROR CALLOC");
        return NULL;
    }
    
    if ((adr_struct_func) == NULL)
    {
        printf("ERROR CALLOC");
        return NULL;
    }

    for (int i = 0; i < num_str; i++)
        adr_struct_func[i] = &(*ptr_struct)[i];
        
    adr_struct_func[0]->string = ptr_buffer;
    adr_struct_func[0]->strlen_string = (int)strlen(ptr_buffer);


    for (int i = 1; i < num_str; i++)
    {
        adr_n_func = strchr(adr_n_func, '\0');
        if ((*adr_n) == NULL)
            break;
        
        adr_n_func++;
        
        adr_struct_func[i]->string = adr_n_func;
        adr_struct_func[i]->strlen_string = (int)strlen(adr_n_func);
    }

    *adr_n = adr_n_func;

    return adr_struct_func;
}

