#include "parser.h"
#include "parser.h"
#include "fileread.h"

void parsmake(char** words_array)
{
    int word_count = 10;
    srand(time(NULL));
    int rnd = rand() % word_count;
    puts(words_array[rnd]);
}