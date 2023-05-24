#include <fileread.h>
#include <generatepsw.h>
#include <input.h>
#include <params.h>
#include <psw.h>
#include <rndword.h>
#include <word.h>
int main(int argc, char* argv[])
{
    int count_words = 1775;
    srand(time(NULL));
    if (argc == 3) {
        int len_pas = atoi(argv[1]);
        int val_pas = atoi(argv[2]);
        gen_psw(len_pas, val_pas, count_words);
        return 0;
    }
    char choice;
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
        user_input_passwords(count_words);
    } else {
        file_input_passwords(count_words);
    }

    return 0;
}