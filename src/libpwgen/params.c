#include "params.h"

long* args()
{
    static long args[3] = {0};
    FILE* fp;
    char str[50];
    char num[50] = "";
    if ((fp = fopen("params.txt", "r")) == NULL) {
        printf("ERROR_OF_OPENING");
        return NULL;
    }
    int k = 0;
    while (!feof(fp)) {
        fgets(str, 50, fp);
        int i = 0;
        int j = 0;
        while (str[i] != '\0') {
            if (isdigit(str[i]) || str[i] == '0')
                num[j++] = str[i];

            i++;
        }
        args[k] = strtol(num, NULL, 10);
        k++;
        memset(num, 0, sizeof(num));
    }

    printf("%ld\n%ld\n%ld\n", args[0], args[1], args[2]);
    return args;
}