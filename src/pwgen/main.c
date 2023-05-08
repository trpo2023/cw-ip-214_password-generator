#include "fileread.h"
#include "parser.h"
#include "psw.h"
int main()
{
    char* message = "Your password: ";
    puts(message);
    char** words_array = array_words();
    parsmake(words_array);
    pass_string(words_array);
    return 0;
}