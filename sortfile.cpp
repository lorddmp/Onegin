#include "sortfile.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

struct_string_and_strlen** bubble_sort_from_start(struct_string_and_strlen** adr_struct, int num_str)
{
    assert(adr_struct);

    struct_string_and_strlen* var = 0;

    for (int i = 0; i < num_str - 1; i++)
    {
        for (int j = 0; j < num_str - i - 1; j++)
        {
            if (my_strcmp_from_start(adr_struct[j], adr_struct[j + 1]) > 0)
            {
                var = adr_struct[j];
                adr_struct[j] = adr_struct[j + 1];
                adr_struct[j + 1] = var;
            }
        }
    }

    return adr_struct;
}

struct_string_and_strlen** bubble_sort_from_end(struct_string_and_strlen** adr_struct, int num_str)
{
    assert(adr_struct);

    struct_string_and_strlen* var = 0;

    for (int i = 0; i < num_str - 1; i++)
    {
        for (int j = 0; j < num_str - i - 1; j++)
        {
            if (my_strcmp_from_end(adr_struct[j], adr_struct[j + 1]) > 0)
            {
                var = adr_struct[j];
                adr_struct[j] = adr_struct[j + 1];
                adr_struct[j + 1] = var;
            }
        }
    }

    return adr_struct;
}

int my_strcmp_from_start(struct_string_and_strlen* a, struct_string_and_strlen* b)
{
    assert(a);
    assert(b);

    int bad_symbols_a = 0, bad_symbols_b = 0;
    bool a_isalpha = 0, b_isalpha = 0;

    for (int i = 0; i < a->strlen_string && i < b->strlen_string; i++)
    {
        if (!a_isalpha && !b_isalpha)
            continue;
        if (a_isalpha && b_isalpha)
            if (tolower(a->string[i + bad_symbols_a]) != tolower(b->string[i + bad_symbols_b]))
                return tolower(a->string[i + bad_symbols_a]) - tolower(b->string[i + bad_symbols_b]); 
        if ((!a_isalpha) && b_isalpha)
        {
            while(1)
            {
                bad_symbols_a++;
                if (isalpha(a->string[i + bad_symbols_a]))
                {
                    if (tolower(a->string[i + bad_symbols_a]) != tolower(b->string[i + bad_symbols_b]))
                        return tolower(a->string[i + bad_symbols_a]) - tolower(b->string[i + bad_symbols_b]);  
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
                if (isalpha(b->string[i + bad_symbols_b]))
                {
                    if (tolower(a->string[i + bad_symbols_a]) != tolower(b->string[i + bad_symbols_b]))
                        return tolower(a->string[i + bad_symbols_a]) - tolower(b->string[i + bad_symbols_b]);
                    else
                        break;
                }
            }
        }
    }
    return 0;
}

int my_strcmp_from_end(struct_string_and_strlen* a, struct_string_and_strlen* b)
{
    assert(a);
    assert(b);
    
    int bad_symbols_a = 0, bad_symbols_b = 0;
    bool a_isalpha = 0, b_isalpha = 0;

    for (int i = a->strlen_string - 1, j = b->strlen_string - 1; i >= 0 && j >= 0; i--, j--)
    {
        a_isalpha = isalpha(a->string[i - bad_symbols_a]);
        b_isalpha = isalpha(b->string[j - bad_symbols_b]);
        if (!a_isalpha && !b_isalpha)
            continue;
        if (a_isalpha && b_isalpha)
            if (tolower(a->string[i - bad_symbols_a]) != tolower(b->string[j - bad_symbols_b]))
                return tolower(a->string[i - bad_symbols_a]) - tolower(b->string[j - bad_symbols_b]); 
        if ((!a_isalpha) && b_isalpha)
        {
            while(1)
            {
                bad_symbols_a++;
                if (isalpha(a->string[i - bad_symbols_a]))
                {
                    if (tolower(a->string[i - bad_symbols_a]) != tolower(b->string[j - bad_symbols_b]))
                        return tolower(a->string[i - bad_symbols_a]) - tolower(b->string[j - bad_symbols_b]);  
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
                if (isalpha(b->string[j - bad_symbols_b]))
                {
                    if (tolower(a->string[i - bad_symbols_a]) != tolower(b->string[j - bad_symbols_b]))
                        return tolower(a->string[i - bad_symbols_a]) - tolower(b->string[j - bad_symbols_b]);
                    else
                        break;
                }
            }
        }
    }
    return 0;
}
