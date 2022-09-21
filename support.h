#ifndef support
#define support

#include <stdio.h>
#include <cstdlib>
#include <ctype.h>


int vivod_postrochno(char** arr_of_ptr, size_t amount_of_str, FILE* output);

int how_many_str(char* arr_of_symb);

int reservo_sort_func(char** arr_of_ptr, size_t amount);

int reverso_comp(const char* fst_str,const char* sec_str);

size_t kvazi_strlen(const char *arr);

int sort_func(char** arr_of_ptr, size_t amount);

int swap(char** fst,char** sec);

int comp(const char* fst_str,const char* sec_str);

size_t alfa_check(const char* symb_ptr);

int isalpha_norm(char symb);

int printf_of_str_kvazi(const char* arr_ptr);

int fprintf_of_str_kvazi(const char* arr_ptr, FILE* file_ptr);


enum Errors : int /// @brief
{
    unknown_error           = -10,
    EOF_error               = EOF,
    arg_function_is_nullptr = 0,
    no_error                = 1
};

#define RED(str) "\033[91m" str "\033[39m"

#define check(condition, type_error)      				        														                   		     \
    if (!(condition))                                                                                                                                \
    {                                                                                                                                                \
		printf("\033[91mОшибка в условии %s в строке %d в файле %s в функции %s \n \033[39m", #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__ ); \
        return type_error;                                                                                                                           \
    }

#endif
