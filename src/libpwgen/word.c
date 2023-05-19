#include <psw.h>
#include <word.h>
void pass_with_word(char* word, int len_pas)
{
    char* psw_str = word;
    int len_psw_str = strlen(psw_str);
    while (len_psw_str + 2 > len_pas) {
        printf("The length of your word is too long, please enter a shorter one: ");
        scanf("%s", word);
        psw_str = word;
        len_psw_str = strlen(psw_str);
    }
    edit_string(psw_str, len_pas);
}
