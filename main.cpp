#include"support.h"
//___________________________________________________________________________________________________
//
//MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!MAIN!!!
//___________________________________________________________________________________________________
int main()
{
    FILE* input = fopen("src", "rb");
    check(input != nullptr, arg_function_is_nullptr);

    fseek(input, 0L, SEEK_END);
    size_t file_elem = ftell(input);
    fseek(input, 0L, SEEK_SET);

    printf("Элементов: %zu\n", file_elem);

    if (file_elem <= 0)
    {
        printf("В файле нет символов:(\n");
        return 1;
    }

    char* arr_of_symb = (char*)calloc(file_elem + 2, sizeof(char));
    check(arr_of_symb != nullptr, arg_function_is_nullptr);

    size_t schitano = fread(arr_of_symb, sizeof(char), file_elem, input);

    printf("Элементов schitano: %zu\n", schitano);

    size_t amount_of_str = how_many_str(arr_of_symb);

    printf("Строк: %zu\n", amount_of_str);

    char** arr_of_ptr = (char**)calloc(amount_of_str + 2, sizeof(char*));
    check(arr_of_ptr != nullptr, arg_function_is_nullptr);

    arr_of_ptr[0] = arr_of_symb;
    size_t schet_strok = 1;

    for(size_t num_symb = 0; schet_strok < amount_of_str; num_symb++)
    {
        if (arr_of_symb[num_symb] == '\n')
        {
            arr_of_ptr[schet_strok] = arr_of_symb + num_symb + 1;

            schet_strok++;
        }
    }

    sort_func(arr_of_ptr, amount_of_str);

    FILE* output = fopen("out", "w");

    fprintf(output, "\n\n\nBegin of sorted by alphabet text:\n\n\n");
    vivod_postrochno(arr_of_ptr, amount_of_str, output);

    reservo_sort_func(arr_of_ptr, amount_of_str);

    fprintf(output, "\n\n\nBegin of sorted by rythm text:\n\n\n");
    vivod_postrochno(arr_of_ptr, amount_of_str, output);

    fprintf(output, "\n\n\nBegin of unchanged text:\n\n\n");
    fprintf(output, "%s", arr_of_symb);

    free(arr_of_symb);
    free(arr_of_ptr);

    fclose(input);
    fclose(output);

    return 0;
}
