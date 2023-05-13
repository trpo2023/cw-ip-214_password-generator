#include <../pwgen/main.h>
int LEN_PAS;
int main()
{
    int val_pas;
    puts("INPUT LENGTH OF PASSWORD");
    scanf("%d", &LEN_PAS);
    puts("INPUT NUMBER OF PASSWORD");
    scanf("%d", &val_pas);

    char** words_array = array_words();
    for (int i = 0; i < val_pas; i++) {
        pass_string(words_array);
    }
}