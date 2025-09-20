#include "sortfile.h"

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
    int strlen_a = (int)strlen(a), strlen_b = (int)strlen(b);
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
    {
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
    }
        return 0;
}   

