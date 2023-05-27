#include <fileread.h>
#include <generatepsw.h>
#include <input.h>
#include <params.h>

void user_input_passwords(int count_words)
{
    int len_pas, val_pas;
    printf("Enter length password: ");
    if (scanf("%d", &len_pas) != 1) {
        printf("Invalid input.\n");
        return;
    }
    printf("Enter amount password: ");
    if (scanf("%d", &val_pas) != 1) {
        printf("Invalid input.\n");
        return;
    }
    printf("Do you want to input your own word? Enter 'y' for yes, 'n' for "
           "no.\n");
    char choice_word;
    scanf(" %c", &choice_word);
    if (choice_word != 'y' && choice_word != 'n') {
        printf("Invalid input.\n");
        return;
    }
    if (choice_word == 'y') {
        char word[50];
        printf("Enter own word: ");
        scanf("%s", word);
        gen_psw_with_word(word, len_pas, val_pas);
    } else {
        gen_psw(len_pas, val_pas, count_words);
    }
}

void file_input_passwords(int count_words)
{
    int len_pas, val_pas;
    FILE* f;
    f = fopen("params.txt", "r");
    if (f == NULL) {
        printf("Error: cannot open file.\n");
        return;
    }
    fseek(f, 0L, SEEK_END);
    if (ftell(f) == 0) {
        printf("Params not found in file. Please enter them through "
               "terminal.\n");
        printf("Enter length password: ");
        if (scanf("%d", &len_pas) != 1) {
            printf("Invalid input.\n");
            return;
        }
        printf("Enter amount password: ");
        if (scanf("%d", &val_pas) != 1) {
            printf("Invalid input.\n");
            return;
        }
        gen_psw(len_pas, val_pas, count_words);
    } else {
        len_pas = args()[0];
        val_pas = args()[1];
        gen_psw(len_pas, val_pas, count_words);
    }
    fclose(f);
}
