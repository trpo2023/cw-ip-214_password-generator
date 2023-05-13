#include <../pwgen/main.h>
#include <fileread.h>
#include <parser.h>
#include <psw.h>
void pass_string(char** words_array)
{
    char* psw_str = words_array[rand() % 1775];
    int len_psw_str = strlen(psw_str);
    while (len_psw_str + 2 > LEN_PAS) {
        psw_str = words_array[rand() % 1775];
        len_psw_str = strlen(psw_str);
    }
    edit_string(psw_str);
}
void edit_string(char* str)
{
    char arr_num[10] = "0123456789";
    char arr_special[8] = "@#$+=-_/";
    int len_str = strlen(str);
    char full_pass[101] = " ";
    add_num(full_pass, arr_num);
    insert_word(full_pass, str, len_str);
    add_special(full_pass, arr_special);
    puts(full_pass);
}
void add_num(char* full_pass, char* arr_num)
{
    for (int i = 0; i < LEN_PAS; i++) {
        full_pass[i] = arr_num[rand() % 10];
    }
}
void insert_word(char* full_pass, char* str, int len_str)
{
    int pos_value = LEN_PAS - len_str - 1;
    int rnd_pos_word = rand() % pos_value;
    int j = 0;
    for (int i = rnd_pos_word; i < len_str + rnd_pos_word - 1; i++) {
        full_pass[i] = str[j];
        j++;
    }
}
void add_special(char* full_pass, char* arr_special)
{
    int rnd_num = rand() % LEN_PAS;
    while (!isdigit(full_pass[rnd_num])) {
        rnd_num = rand() % LEN_PAS;
    }
    full_pass[rnd_num] = arr_special[rand() % 6];
}