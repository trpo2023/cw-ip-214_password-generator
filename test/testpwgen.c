#include "../src/libpwgen/psw.h"
#include <ctest.h>
#include <ctype.h>
#include <parser.h>
#include <fileread.h>

CTEST(ctest, DIGIT)
{
    int expected = 0;
    int reality = 1;
    char test_str[] = "apple ";
    char* password = (char*)malloc(sizeof(char) * (strlen(test_str)+2));
    password = edit_string(test_str, (strlen(test_str)+2));
    for (int i = 0; i < sizeof(password); i++) {
        if (isdigit(password[i])) {
            expected = 1;
            break;
        }
    }
    ASSERT_DBL_NEAR(expected, reality);
}
CTEST(ctest, SPECIAL_SYMBOL)
{
    char arr_special[8] = "@#$+=-_/";
    int expected = 0;
    int reality = 1;
    char test_str[] = "apple ";
    char* password = (char*)malloc(sizeof(char) * (10));
    password = edit_string(test_str, 10);
    for (int i = 0; i < sizeof(password); i++) {
        for(int j = 0; j < strlen(arr_special); j++){
            if (arr_special[j] == password[i]) {
            expected = 1;
            break;
        }
        }
        
    }
    ASSERT_DBL_NEAR(expected, reality);
}
CTEST(ctest, LENGTH_STRING)
{
    int expected = 0;
    int reality = 1;
    char test_str[] = "apple ";
    char* password = (char*)malloc(sizeof(char) * (10));
    int count = 0;
    password = edit_string(test_str, 10);
    for(int i = 0; i < strlen(password); i++){
        if((password[i] >= 'a')&&(password[i] < 'z')){
            count++;
            printf("%d", i);
        }
    }
    if (count == 5){
        expected = 1;
    }
    printf("%d", count);
    ASSERT_DBL_NEAR(expected, reality);
}

CTEST(ctest, NOT_NULL_USER_ARGS)
{
    long* arr = args();
    ASSERT_NOT_NULL(arr);
}

CTEST(ctest, NOT_NULL_WORD_LIST)
{
    char** words_array=array_words();
    ASSERT_NOT_NULL(words_array);
}

CTEST(ctest, NOT_NULL_WORD)
{
    char** words_array=array_words();
    char* pars= parsmake(words_array);
    ASSERT_NOT_NULL(pars);
}
