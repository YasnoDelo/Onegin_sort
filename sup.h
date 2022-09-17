#ifndef support
#define support


enum Errors : int /// @brief Набор возможных ошибок
{
    unknown_error           = -10,
    EOF_error               = EOF,
    arg_function_is_nullptr = 0,
    no_error                = 1
}; 

#define check(condition, type_error)      				        														                   		     \
    if (!(condition))                                                                                                                                \
    {                                                                                                                                                \
		printf("\033[91mОшибка в условии %s в строке %d в файле %s в функции %s \n \033[39m", #condition, __LINE__, __FILE__, __PRETTY_FUNCTION__ ); \
        return type_error;                                                                                                                           \
    }                  

#define RED(str) "\033[91m" str "\033[39m" 

#endif
