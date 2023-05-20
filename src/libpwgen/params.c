#include <params.h>

int* args()
{
    int* args = (int*)malloc(sizeof(int) * 3);
    FILE* fp;
    char str[50];
    char num[50] = "";
    if ((fp = fopen("params.txt", "r")) == NULL) {
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
    fclose(fp);
    return args;
}
