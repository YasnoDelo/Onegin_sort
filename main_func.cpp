#include "incl.h"
#include "sup.h"

int main()
{
    size_t file_elements = 0/*, check_num = 0*/;

    FILE *input_file_ptr = fopen("origin", "r");
    check(input_file_ptr != nullptr, arg_function_is_nullptr);

    fseek(input_file_ptr, 0L, SEEK_END);
    file_elements = (size_t)ftell(input_file_ptr);
    fseek(input_file_ptr, 0L, SEEK_SET);

    char* arr_of_symb = (char*)calloc(file_elements + 2, sizeof(char));
    check(arr_of_symb != nullptr, arg_function_is_nullptr);

    /*if ( (check_num = */

    fread(arr_of_symb, sizeof(char), file_elements, input_file_ptr);
    arr_of_symb[file_elements+1] = '\0';

    FILE* output_file_ptr = fopen("output","w");

    /*) == file_elements)
        printf("Считаны все символы \n");
    else
        printf("Считаны НЕ все символы \n");

    printf("file_elements = %zu\n", file_elements);
    printf("check_num = %zu\n", check_num);

    printf("%s", arr_of_symb);*/

    size_t cur_elem = 0, string_num = 1;

    while (*(arr_of_symb + cur_elem) != '\0') //Считаем количество строк
    {
        printf("%zu\n", cur_elem);
        //printf ("%c", arr_of_symb[cur_elem]);
        if ( *(arr_of_symb + cur_elem) == '\n' )
        {string_num++;

            printf("%zu\n", string_num);
        }
        cur_elem++;printf("Хы\n");
        check(cur_elem <= file_elements, unknown_error);
    }
printf("Хы\n");
     if (cur_elem != file_elements)
         printf("Что-то странное, пробежалось %zu элементов из %zu\n", cur_elem, file_elements);

    printf("Хы");
    printf("Строк: %zu\n", string_num);
    printf("Хы");

    char** arr_of_pointers = (char**)calloc(string_num + 2, sizeof(char*));
    printf("Хы");
    check(arr_of_pointers != nullptr, arg_function_is_nullptr);

    printf("До кусорта");
    qsort(arr_of_pointers, string_num, sizeof(char*), letter_comp);
    printf("После кусорта");

    printf("Отсортированные строки:\n");

    for(size_t schet = 0; schet <= string_num; schet++)
    {
        printf("Номер строки: %zu", schet);
        for(size_t inside_schet = 0; *(arr_of_pointers[schet] + inside_schet) != '\n'; inside_schet++)
            fprintf(output_file_ptr, "%c", *(*(arr_of_pointers + schet) + inside_schet));
        fputc('\n', output_file_ptr);
    }

    free(arr_of_symb);
    free(arr_of_pointers);

    fclose(output_file_ptr);
    fclose(input_file_ptr);

    return 0;
}
