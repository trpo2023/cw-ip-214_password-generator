#include <fileread.h>
#include <psw.h>
#include <rndword.h>
void pass_string(
        char** words_array, int len_pas, int count_words, char* full_pass)
{
    char* psw_str = words_array[rand() % count_words];
    int len_psw_str = strlen(psw_str);
    while (len_psw_str + 2 > len_pas) {
        psw_str = words_array[rand() % count_words];
        len_psw_str = strlen(psw_str);
    }
    edit_string(psw_str, len_pas, full_pass);
}

void edit_string(char* str, int len_pas, char* full_pass)
{
    char arr_num[10] = "0123456789";
    char arr_special[8] = "@#$+=-_/";
    int len_str = strlen(str);
    add_num(full_pass, arr_num, len_pas);
    insert_word(full_pass, str, len_str, len_pas);
    add_special(full_pass, arr_special, len_pas);
}

void add_num(char* full_pass, char* arr_num, int len_pas)
{
    for (int i = 0; i < len_pas; i++) {
        full_pass[i] = arr_num[rand() % 10];
    }
}

void insert_word(char* full_pass, char* str, int len_str, int len_pas)
{
    int pos_value = len_pas - len_str - 1;
    int rnd_pos_word = rand() % pos_value;
    int j = 0;
    for (int i = rnd_pos_word; i < len_str + rnd_pos_word; i++) {
        if (str[j] != '\n') {
            full_pass[i] = str[j];
            j++;
        }
    }
}

void add_special(char* full_pass, char* arr_special, int len_pas)
{
    int rnd_num = rand() % len_pas;
    while (!isdigit(full_pass[rnd_num])) {
        rnd_num = rand() % len_pas;
    }
    full_pass[rnd_num] = arr_special[rand() % sizeof(arr_special)];
}