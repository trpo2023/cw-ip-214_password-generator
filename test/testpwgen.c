#include <params.h>
#include <psw.h>
#include <ctest.h>
#include <ctype.h>
#include <fileread.h>
#include <rndword.h>

CTEST(ctest, DIGIT)
{
    int expected = 0;
    int reality = 1;
    int* len = args();
    char** words_array = array_words();
    char* test_str= parsmake(words_array);
 
    while(strlen(test_str) >= len[0] - 1)
         test_str= parsmake(words_array);
    char* password;   
    if(len[0]){
        password = (char*)malloc(sizeof(char) * len[0]);
        password = edit_string(test_str, len[0]); 
         for (int i = 0; i < len[0]; i++) {
            if (isdigit(password[i]) || password[i]=='0') {
              expected = 1;
              break;
            }
        }
    }
    else expected = 1;
    ASSERT_EQUAL(expected, reality);
}

CTEST(ctest, SPECIAL_SYMBOL)
{
    char arr_special[8] = "@#$+=-_/";
    int expected = 0;
    int reality = 1;
    int* len=args();
    char** words_array = array_words();
    char* test_str= parsmake(words_array);
    while(strlen(test_str) >= len[0] - 1)
         test_str= parsmake(words_array);
    char* password;   
    if(len[0]){
    char* password = (char*)malloc(sizeof(char) * len[0]);
    password = edit_string(test_str, len[0]);
    for (int i = 0; i < len[0]; i++) {
        for (int j = 0; j < strlen(arr_special); j++) {
            if (arr_special[j] == password[i]) {
                expected = 1;
                break;
            }
        }
    }
    }
    else expected = 1;
    ASSERT_EQUAL(expected, reality);
}

CTEST(ctest, LENGTH_STRING)
{
    int expected = 0;
    int reality = 1;
    int* len=args();
    char** words_array = array_words();
    char* test_str= parsmake(words_array);
    while(strlen(test_str) >= len[0] - 1)
         test_str= parsmake(words_array);
    char* password;   
    if(len[0]){
    char* password = (char*)malloc(sizeof(char) * len[0]);
    int count = 0;
    password = edit_string(test_str, len[0]);
    for (int i = 0; i < strlen(test_str) - 1; i++) {
        if ((test_str[i] >= 'a') && (test_str[i] <= 'z')) 
            expected = 1;
        else{
            expected = 0;
            break;
        }
    }
    }
    else expected = 1;
    ASSERT_EQUAL(expected, reality);
}

CTEST(ctest, NOT_NULL_USER_ARGS)
{
    int* arr = args();
    ASSERT_NOT_NULL(arr);
}

CTEST(ctest, NOT_NULL_WORD_LIST)
{
    char** words_array = array_words();
    ASSERT_NOT_NULL(words_array);
}

CTEST(ctest, NOT_NULL_WORD)
{
    char** words_array = array_words();
    char* pars = parsmake(words_array);
    ASSERT_NOT_NULL(pars);
}
