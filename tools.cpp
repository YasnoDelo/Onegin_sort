#include"support.h"

int fprintf_of_str_kvazi(const char* arr_ptr, FILE* file_ptr)
{
    check(arr_ptr != nullptr, arg_function_is_nullptr);

    for(size_t schet = 0; arr_ptr[schet] != '\n'; schet++)
        fputc(arr_ptr[schet], file_ptr);

    fputc('\n', file_ptr);

    return 0;
}

int printf_of_str_kvazi(const char* arr_ptr)
{
    check(arr_ptr != nullptr, arg_function_is_nullptr);

    for(size_t schet = 0; arr_ptr[schet] != '\n'; schet++)
        putchar(arr_ptr[schet]);

    putchar('\n');

    return 0;
}

int isalpha_norm(char symb)
{
    if (( (symb >= 65) && (symb <= 90) ) || ( (symb >= 97) && (symb <= 122) ))
        return 1;
    else
        return 0;
    return 0;
}

size_t alfa_check(const char* symb_ptr)
{
    check(symb_ptr != nullptr, arg_function_is_nullptr);

    size_t sdvig = 0;

    while ( (!isalpha( (int)(symb_ptr[sdvig]) )) || ( symb_ptr[sdvig]  !='\n') || ( symb_ptr[sdvig] !='\0'))
    {
        sdvig++;
    }

    return sdvig;
}

int comp(const char* fst_str,const char* sec_str)
{
    check(fst_str != 0, arg_function_is_nullptr);
    check(sec_str != 0, arg_function_is_nullptr);

     int razn = 0;

     if( (*(fst_str) == '\n') || (*(sec_str) == '\n') || (*(sec_str) == '\0') || (*(fst_str) == '\0'))
         return 0;

     while (isalpha_norm(*(fst_str)) == 0)
         fst_str++;

     while (isalpha_norm((*(sec_str))) == 0)
         sec_str++;

     while ( *(fst_str) == *(sec_str))
     {
        fst_str++;
        sec_str++;

        while (isalpha_norm((*(fst_str))) == 0)
            fst_str++;
        while (isalpha_norm((*(sec_str))) == 0)
            sec_str++;
     }

    razn = *(fst_str) - *(sec_str);

    return razn;}

int swap(char** fst,char** sec)
{
    check(fst != nullptr, arg_function_is_nullptr);
    check(sec != nullptr, arg_function_is_nullptr);

    char* yeur = *fst;
    *fst = *sec;
    *sec = yeur;

    return 0;
}

int sort_func(char** arr_of_ptr, size_t amount)
{
    check(arr_of_ptr != nullptr, arg_function_is_nullptr);

    for(size_t out_count = 0; out_count < amount - 1; out_count++)
    {
        size_t swapped = 0;

        for(size_t in_count = 0; in_count < amount - 1; in_count++)
        {
            if (comp(arr_of_ptr[in_count], arr_of_ptr[in_count + 1]) >= 0)
            {
                swap(&arr_of_ptr[in_count], &arr_of_ptr[in_count + 1]);
                swapped = 1;
            }
        }

        if(swapped == 0)
            break;
    }

    return 0;
}

size_t kvazi_strlen(const char *arr)
{
    size_t count = 0;

    while (*(arr + count) != '\n')
    {
        count++;
    }

    return count;
}

int reverso_comp(const char* fst_str,const char* sec_str)
{
    check(fst_str != 0, arg_function_is_nullptr);
    check(sec_str != 0, arg_function_is_nullptr);

     int razn = 0;

     size_t fst_len = kvazi_strlen(fst_str);
     size_t sec_len = kvazi_strlen(sec_str);

     fst_str += fst_len - 1;
     sec_str += sec_len - 1;

     if( (*(fst_str) == '\n') || (*(sec_str) == '\n') || (*(sec_str) == '\0') || (*(fst_str) == '\0'))
         return 0;

    size_t stop = 0;

     while (isalpha_norm(*(fst_str)) == 0)
         fst_str--;

     while (isalpha_norm((*(sec_str))) == 0)
         sec_str--;

     while ( *(fst_str) == *(sec_str))
     {
        stop++;

        fst_str--;
        sec_str--;

        if ((stop == fst_len) || (stop == sec_len))
            break;

        while (isalpha_norm((*(fst_str))) == 0)
            fst_str--;
        while (isalpha_norm((*(sec_str))) == 0)
            sec_str--;
     }

    razn = *(fst_str) - *(sec_str);

    return razn;
}

int reservo_sort_func(char** arr_of_ptr, size_t amount)
{
    check(arr_of_ptr != nullptr, arg_function_is_nullptr);

    for(size_t out_count = 0; out_count < amount - 1; out_count++)
    {
        size_t swapped = 0;

        for(size_t in_count = 0; in_count < amount - 1; in_count++)
        {
            if (reverso_comp(arr_of_ptr[in_count], arr_of_ptr[in_count + 1]) >= 0)
            {
                swap(&arr_of_ptr[in_count], &arr_of_ptr[in_count + 1]);
                swapped = 1;
            }
        }

        if(swapped == 0)
            break;
    }

    return 0;
}

int how_many_str(char* arr_of_symb)
{
    size_t am_str = 0;

    for(size_t schet = 0; arr_of_symb[schet] != '\0'; schet++)
    {
        if (arr_of_symb[schet] == '\n')
            am_str++;
    }
    return am_str;
}

int vivod_postrochno(char** arr_of_ptr, size_t amount_of_str, FILE* output)
{
    for(size_t num_str = 0; num_str < amount_of_str; num_str++)
    {
        printf_of_str_kvazi(arr_of_ptr[num_str]);
        fprintf_of_str_kvazi(arr_of_ptr[num_str], output);
    }

    return 0;
}
