#include "fileread.h"
int count_words = 10;
const int str_size = 50;

char** array_words()
{
    char** words_array = (char**)malloc(sizeof(char*) * count_words);
    for (int i = 0; i < count_words; i++)
        words_array[i] = (char*)malloc(sizeof(char) * str_size);
    int i = 0;
    char str[str_size];
    char* estr;
    FILE* file;
    file = fopen("vocabulary.txt", "r");
    while (!feof(file)) {
        estr = fgets(str, sizeof(str), file);
        if (estr == NULL) {
            if (feof(file) != 0)
                break;
            else {
                printf("ERROR");
                break;
            }
        }
        strcpy(words_array[i], estr);
        i++;
    }
    return words_array;
}