#include "open_file.h"
#include "output_in_file.h"
#include "work_with_file.h"
#include "sortfile.h"
#include "structure.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#define OUTPUT_FILENAME_START "onegin_startsort.txt"
#define OUTPUT_FILENAME_END "onegin_endsort.txt"

int main()
{
    setbuf(stdout, 0);
    int num_str = 0;
    struct stat buf = {0};
    struct_string_and_strlen** adr_struct = {0};
    struct_string_and_strlen* ptr_struct = {0};
    FILE* fp = 0;
    char* ptr_buffer = 0;
    char* adr_n = 0;
       
    if (open_file(&fp, &buf))
    {
        free(fp);
        return 1;
    }

    if (work_with_file(fp, &buf, &ptr_buffer, &adr_n, &num_str))
    {
        free(fp);
        free(ptr_buffer);
        return 1;
    }
    
    adr_struct = massive_address(&ptr_struct, ptr_buffer, &adr_n, num_str);

    if (adr_struct == NULL)
    {
        free(fp);
        free(ptr_buffer);
        free(adr_struct);
        free(ptr_struct);
        return 1;
    }
    
    adr_struct = bubble_sort_from_start(adr_struct, num_str);

    if (output_in_file(OUTPUT_FILENAME_START, adr_struct, num_str))
    {
        free(fp);
        free(ptr_buffer);
        free(adr_struct);
        free(ptr_struct);
        return 1;
    }
    adr_struct = bubble_sort_from_end(adr_struct, num_str);

    if (output_in_file(OUTPUT_FILENAME_END, adr_struct, num_str))
    {
        free(fp);
        free(ptr_buffer);
        free(adr_struct);
        free(ptr_struct);
        return 1;
    }
    

    free (ptr_buffer);
    free (adr_struct);
    free(ptr_struct);
    fclose (fp);
    
    return 0;
}