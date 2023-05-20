#include <fileread.h>
#include <parser.h>

char* parsmake(char** words_array)
{
    int word_count = 1775;
    srand(time(NULL));
    int rnd = rand() % word_count;
    char* word = words_array[rnd];
    return word;
}
