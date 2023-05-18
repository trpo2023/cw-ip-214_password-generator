#include "fileread.h"
#include "params.h"
#include "parser.h"
#include "psw.h"
int main(int argc, char* argv[])
{
    srand(time(NULL));
    char choice;
    printf("Do you want enter input data? y/n\n");
    scanf("%c", &choice);
    if (choice == 'y') {
        if ((argc > 3 && argc != 1) || argc == 2) {
            printf("Usage: %s LEN_PAS val_pas\n", argv[0]);
            exit(1);
        }
        int len_pas = 0, val_pas = 0;
        printf("Enter length password: ");
        scanf("%d", &len_pas);
        printf("Enter amount password: ");
        scanf("%d", &val_pas);
        char** words_array = array_words();
        for (int i = 0; i < val_pas; i++) {
            pass_string(words_array, len_pas);
        }
    } else {
        FILE* f;
        f = fopen("params.txt", "r");
        if (f == NULL) {
            printf("Error: cannot open file.\n");
            return 1;
        }
        fseek(f, 0L, SEEK_END);
        if (ftell(f) == 0) {
            printf("Params not found in file. Please enter them through "
                   "terminal.\n");
            int len_pas, val_pas;
            printf("Enter length password: ");
            scanf("%d", &len_pas);
            printf("Enter amount password: ");
            scanf("%d", &val_pas);
            char** words_array = array_words();
            for (int i = 0; i < val_pas; i++) {
                pass_string(words_array, len_pas);
            }
        } else {
            rewind(f);
            int len_pas, val_pas;
            fscanf(f, "%d %d", &len_pas, &val_pas);
            char** words_array = array_words();
            for (int i = 0; i < val_pas; i++) {
                pass_string(words_array, len_pas);
            }
        }
        fclose(f);
    }
    return 0;
}