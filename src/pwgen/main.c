#include "fileread.h"
#include "params.h"
#include "parser.h"
#include "psw.h"
int main(int argc, char* argv[])
{
    int len_pas = 0, val_pas = 0;
    if ((argc > 3 && argc != 1) || argc == 2) {
        printf("Usage: %s LEN_PAS val_pas\n", argv[0]);
        exit(1);
    }
    if (argc == 1) {
        printf("Enter length password: ");
        scanf("%d", &len_pas);
        printf("Enter amount password: ");
        scanf("%d", &val_pas);
    } else {
        len_pas = atoi(argv[1]);
        val_pas = atoi(argv[2]);
    }
    char** words_array = array_words();
    for (int i = 0; i < val_pas; i++) {
        pass_string(words_array, len_pas);
    }
}