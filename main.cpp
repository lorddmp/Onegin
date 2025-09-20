#include "open_file.h"
#include "output_in_file.h"
#include "work_with_file.h"
#include "sortfile.h"

int main()
{
    setbuf(stdout, 0);
    int num_str = 0;
    struct stat buf = {0};
    FILE* fp = 0;
    char* ptr_buffer = 0;
    char* adr_n = 0;
    char** adr_adr = 0;
    
    
    open_file(&fp, &buf);

    work_with_file(&fp, &buf, &ptr_buffer, &adr_n, &num_str);
     
    massive_address(&adr_adr, ptr_buffer, &adr_n, num_str);

    bubble_sort(FROM_START, &adr_adr, num_str);

    output_in_file(OUTPUT_FILENAME_START, adr_adr, num_str);

    bubble_sort(FROM_END, &adr_adr, num_str);

    output_in_file(OUTPUT_FILENAME_END, adr_adr, num_str);

    free (ptr_buffer);
    free (adr_adr);
    fclose (fp);
    
    return 0;
}