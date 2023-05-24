#include <fileread.h>
#include <rndword.h>
char** array_words(int count_words)
{
    const int STR_SIZE = 256;
    char** words_array = calloc(count_words, sizeof(char*));
    for (int i = 0; i < count_words; i++) {
        words_array[i] = calloc(STR_SIZE, sizeof(char));
    }
    int i = 0;
    FILE* file = fopen("vocabulary.txt", "r");
    if (!file) {
        printf("Error: cannot open file.\n");
        free(words_array);
        exit(1);
    }
    while (i < count_words && fgets(words_array[i], STR_SIZE, file)) {
        int len = strlen(words_array[i]);
        if (len > 0 && words_array[i][len - 1] == '\n') {
            words_array[i][len - 1] = '\0';
        }
        i++;
    }
    fclose(file);
    return words_array;
}