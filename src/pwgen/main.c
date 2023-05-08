#include "fileread.h"
#include "parser.h"
#include "psw.h"
int main()
{
    char** words_array = array_words();
    parsmake(words_array);
    pass_string(words_array);
}