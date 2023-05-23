#include <fileread.h>
#include <params.h>
#include <rndword.h>
#include <psw.h>
#include <word.h>
int main(int argc, char* argv[])
{
    srand(time(NULL));
    int len_pas = 0, val_pas = 0;
    char choice;
    if (argc == 3) {
        len_pas = atoi(argv[1]);
        val_pas = atoi(argv[2]);
        char** words_array = array_words();
        for (int i = 0; i < val_pas; i++) {
            pass_string(words_array, len_pas);
        }
        free(words_array);
        return 0;
    }
    printf("Do you want to enter input data? Enter 'y' for yes, 'n' for no.\n");
    scanf(" %c", &choice);
    if (choice != 'y' && choice != 'n') {
        printf("Invalid input.\n");
        return 0;
    }
    if (choice == 'y') {
        if ((argc > 3 && argc != 1) || argc == 2) {
            printf("Usage: %s LEN_PAS val_pas\n", argv[0]);
            exit(1);
        }
        printf("Enter length password: ");
        int input_check = scanf("%d", &len_pas);
        if (input_check != 1) {
            printf("Invalid input.\n");
            return 0;
        }
        printf("Enter amount password: ");
        input_check = scanf("%d", &val_pas);
        if (input_check != 1) {
            printf("Invalid input.\n");
            return 0;
        }
        printf("Do you want to input your own word? Enter 'y' for yes, 'n' for "
               "no.\n");
        char choice_word;
        scanf(" %c", &choice_word);
        if (choice_word != 'y' && choice_word != 'n') {
            printf("Invalid input.\n");
            return 0;
        }
        if (choice_word == 'y') {
            char word[50];
            printf("Enter own word: ");
            scanf("%s", word);
            for (int i = 0; i < val_pas; i++) {
                pass_with_word(word, len_pas);
            }
        } else {
            char** words_array = array_words();
            for (int i = 0; i < val_pas; i++) {
                pass_string(words_array, len_pas);
            }
        }
    } else {
        FILE* f;
        f = fopen("params.txt", "r");
        if (f == NULL) {
            printf("Error: cannot open file.\n");
            return 0;
        }
        fseek(f, 0L, SEEK_END);
        if (ftell(f) == 0) {
            printf("Params not found in file. Please enter them through "
                   "terminal.\n");
            printf("Enter length password: ");
            int input_check = scanf("%d", &len_pas);
            if (input_check != 1) {
                printf("Invalid input.\n");
                return 0;
            }
            printf("Enter amount password: ");
            input_check = scanf("%d", &val_pas);
            if (input_check != 1) {
                printf("Invalid input.\n");
                return 0;
            }
            char** words_array = array_words();
            for (int i = 0; i < val_pas; i++) {
                pass_string(words_array, len_pas);
            }
        } else {
            len_pas = args()[0];
            val_pas = args()[1];
            char** words_array = array_words();
            for (int i = 0; i < val_pas; i++) {
                pass_string(words_array, len_pas);
            }
        }
        fclose(f);
    }
    
    return 0;
}