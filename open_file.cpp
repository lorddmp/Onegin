#include "open_file.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>

#define INPUT_FILENAME "onegin.txt"

int open_file(FILE** fp, struct stat* buf)
{
    assert(fp);
    assert(buf);
    
    *fp = fopen(INPUT_FILENAME, "r");
    if (*fp == NULL)
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