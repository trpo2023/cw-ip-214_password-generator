#include <fileread.h>
#include <generatepsw.h>
#include <psw.h>
#include <word.h>
void gen_psw(int len_pas, int val_pas, int count_words)
{
    char** words_array = array_words(count_words);
    for (int i = 0; i < val_pas; i++) {
        char full_pass[256] = "";
        pass_string(words_array, len_pas, count_words, full_pass);
        puts(full_pass);
    }
}

void gen_psw_with_word(char* word, int len_pas, int val_pas)
{
    for (int i = 0; i < val_pas; i++) {
        char full_pass[256] = "";
        pass_with_word(word, len_pas, full_pass);
        puts(full_pass);
    }
}