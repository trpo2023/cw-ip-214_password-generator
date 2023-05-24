#include <fileread.h>
#include <rndword.h>

char* parsmake(char** words_array, int count_words)
{
    srand(time(NULL));
    int rnd = rand() % count_words;
    char* word = words_array[rnd];
    return word;
}
