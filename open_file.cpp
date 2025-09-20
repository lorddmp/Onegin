#include "open_file.h"

int open_file(FILE** fp, struct stat* buf)
{
    *fp = fopen(INPUT_FILENAME, "r");
    if (fp == NULL)
    {
        printf("Error in reading file\n");
        return 1;
    }
    
    if (fstat(fileno(*fp), buf) == -1)
    {
        fclose(*fp);
        perror("Error\n");
        return 1;
    }
    
    if (buf->st_size == 0)
    {
        printf("Where is Onegin&\n");
        fclose(*fp);
        return 1;
    }

    return 0;
}