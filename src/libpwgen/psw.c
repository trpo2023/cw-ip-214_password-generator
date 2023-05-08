#include "psw.h"
#include "fileread.h"
#include "parser.h"

void pass_string(char** words_array)
{
    char *psw_str = parsmake(words_array);
    while (strlen(psw_str) >= strlen(words_array[0]) - 2) {
        psw_str = parsmake(words_array);
    }
    puts(psw_str);
}
