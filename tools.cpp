#include "incl.h"
#include "sup.h"

int letter_comp(const void* fst_str, const void* sec_str) //принимает значения ячеек из массива указателей, то есть указатели на нужные строки
{
    check(fst_str != nullptr, arg_function_is_nullptr);
    check(sec_str != nullptr, arg_function_is_nullptr);

    size_t fst_str_mv = alfa_check(fst_str);
    size_t sec_str_mv = alfa_check(sec_str);

    while (*( (char*)fst_str + fst_str_mv ) == *( (char*)sec_str + sec_str_mv ))
    {
        fst_str_mv++;
        sec_str_mv++;

        fst_str_mv += alfa_check(fst_str);
        sec_str_mv += alfa_check(sec_str);

    }
    return *( ((char*)fst_str + fst_str_mv ) - *( (char*)sec_str + sec_str_mv ));
}

size_t alfa_check(const void* symb_ptr)
{
    check(symb_ptr != nullptr, arg_function_is_nullptr);
    size_t sdvig = 0;

    while ( !isalpha( *( (char*)symb_ptr + sdvig ) ) )
        sdvig++;

    return sdvig;
}

