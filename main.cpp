#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define INPUT_FILENAME "onegin.txt"
#define OUTPUT_FILENAME_START "onegin_startsort.txt"
#define OUTPUT_FILENAME_END "onegin_endsort.txt"
#define FROM_START 0
#define FROM_END 1

int open_file(FILE** fp, struct stat* buf);

int work_with_file(FILE** fp, struct stat* buf, char** ptr_buffer, char** adr_n,int* final_elems, int* num_str);

int massive_address(char*** adr_adr, FILE* fp, char* ptr_buffer, char** adr_n, int num_str);

int output_in_file(const char* filename, char** adr_adr, int num_str);

int bubble_sort(bool mode, char*** adr_adr, int num_str);

int my_strcmp(bool mode, char* a, char* b);

int main()
{
    setbuf(stdout, 0);
    int num_str = 0, final_elems = 0;
    struct stat buf = {0};
    FILE* fp = 0;
    char* ptr_buffer = 0;
    char* adr_n = 0;
    char** adr_adr = 0;
    
    
    open_file(&fp, &buf);

    work_with_file(&fp, &buf, &ptr_buffer, &adr_n, &final_elems, &num_str);
     
    massive_address(&adr_adr, fp, ptr_buffer, &adr_n, num_str);

    bubble_sort(FROM_START, &adr_adr, num_str);

    output_in_file(OUTPUT_FILENAME_START, adr_adr, num_str);

    bubble_sort(FROM_END, &adr_adr, num_str);

    output_in_file(OUTPUT_FILENAME_END, adr_adr, num_str);

    free (ptr_buffer);
    free (adr_adr);
    fclose (fp);
    
    return 0;
}

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

int work_with_file(FILE** fp, struct stat* buf, char** ptr_buffer, char** adr_n,int* final_elems, int* num_str)
{
    *ptr_buffer = (char*)calloc(buf->st_size + 1, sizeof(char));
    if (ptr_buffer == NULL)
    {
        printf("Error in calloc\n");
        return 1;
    }
    
    *final_elems = fread(*ptr_buffer, sizeof(char), buf->st_size, *fp);
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

int massive_address(char*** adr_adr, FILE* fp, char* ptr_buffer, char** adr_n, int num_str)
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

int bubble_sort(bool mode, char*** adr_adr, int num_str)
{
    char* var = 0;
    for (int i = 0; i < num_str; i++)
    {
        int num_strcmp = 0;
        for (int j = 0; j < num_str - 1; j++)
        {
            if (my_strcmp(mode, *(*adr_adr + j), *(*adr_adr + j + 1)) > 0)
            {
                var = *(*adr_adr + j);
                *(*adr_adr + j) = *(*adr_adr + j + 1);
                *(*adr_adr + j + 1) = var;
                num_strcmp++;
            }
        }
        if (num_strcmp == 0)
            break;
        
    }
    return 0;
}

int my_strcmp(bool mode, char* a, char* b)
{
    int bad_symbols_a = 0, bad_symbols_b = 0;
    int strlen_a = strlen(a), strlen_b = strlen(b);
    bool a_isalpha = 0, b_isalpha = 0;

    if (mode == FROM_START)
        for (int i = 0; i < strlen_a && i < strlen_b; i++)
        {
            a_isalpha = isalpha(a[i + bad_symbols_a]);
            b_isalpha = isalpha(b[i + bad_symbols_b]);

            if (!a_isalpha && !b_isalpha)
                continue;

            if (a_isalpha && b_isalpha)
                if (tolower(a[i + bad_symbols_a]) != tolower(b[i + bad_symbols_b]))
                    return tolower(a[i + bad_symbols_a]) - tolower(b[i + bad_symbols_b]); 

            if ((!a_isalpha) && b_isalpha)
            {
                while(1)
                {
                    bad_symbols_a++;
                    if (isalpha(a[i + bad_symbols_a]))
                    {
                        if (tolower(a[i + bad_symbols_a]) != tolower(b[i + bad_symbols_b]))
                            return tolower(a[i + bad_symbols_a]) - tolower(b[i + bad_symbols_b]);  
                        else
                            break;
                    }
                }
            }

            if (a_isalpha && (!b_isalpha))
            {
                while(1)
                {
                    bad_symbols_b++;
                    if (isalpha(b[i + bad_symbols_b]))
                    {
                        if (tolower(a[i + bad_symbols_a]) != tolower(b[i + bad_symbols_b]))
                            return tolower(a[i + bad_symbols_a]) - tolower(b[i + bad_symbols_b]);
                        else
                            break;
                    }
                }
            }
        }
    else
        for (int i = strlen_a - 1, j = strlen_b - 1; i >= 0 && j >= 0; i--, j--)
        {
            a_isalpha = isalpha(a[i - bad_symbols_a]);
            b_isalpha = isalpha(b[j - bad_symbols_b]);

            if (!a_isalpha && !b_isalpha)
                continue;

            if (a_isalpha && b_isalpha)
                if (tolower(a[i - bad_symbols_a]) != tolower(b[j - bad_symbols_b]))
                    return tolower(a[i - bad_symbols_a]) - tolower(b[j - bad_symbols_b]); 

            if ((!a_isalpha) && b_isalpha)
            {
                while(1)
                {
                    bad_symbols_a++;
                    if (isalpha(a[i - bad_symbols_a]))
                    {
                        if (tolower(a[i - bad_symbols_a]) != tolower(b[j - bad_symbols_b]))
                            return tolower(a[i - bad_symbols_a]) - tolower(b[j - bad_symbols_b]);  
                        else
                            break;
                    }
                }
            }

            if (a_isalpha && (!b_isalpha))
            {
                while(1)
                {
                    bad_symbols_b++;
                    if (isalpha(b[j - bad_symbols_b]))
                    {
                        if (tolower(a[i - bad_symbols_a]) != tolower(b[j - bad_symbols_b]))
                            return tolower(a[i - bad_symbols_a]) - tolower(b[j - bad_symbols_b]);
                        else
                            break;
                    }
                }
            }
        }

        return 0;
}   