#include <params.h>
#include <psw.h>
#include <ctest.h>
#include <ctype.h>
#include <fileread.h>
#include <rndword.h>
#define count_words 1775

CTEST(ctest, SPECIAL1)
{
    int expected = 1;
    int reality = 0;
    char arr_special[8] = "@#$+=-_/";
    char str1[] = "ab3def5";
    add_special(str1, arr_special, 7);
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 8; j++){
            if(arr_special[j] == str1[i]){
                reality = 1;
                break;
            }
        }
    }
    ASSERT_EQUAL(expected, reality);
}
CTEST(ctest, SPECIAL2)
{
    int expected = 1;
    int reality = 0;
    char arr_special[8] = "@#$+=-_/";
    char str1[] = "123456789";
    add_special(str1, arr_special, 9);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 8; j++){
            if(arr_special[j] == str1[i]){
                reality = 1;
                break;
            }
        }
    }
    ASSERT_EQUAL(expected, reality);
}
CTEST(ctest, SPECIAL3)
{
    int expected = 1;
    int reality = 0;
    char arr_special[8] = "@#$+=-_/";
    char str1[] = "asdsas6";
    add_special(str1, arr_special, 7);
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 8; j++){
            if(arr_special[j] == str1[i]){
                reality = 1;
                break;
            }
        }
    }
    ASSERT_EQUAL(expected, reality);
}
CTEST(ctest, NUMBERS1)
{
    int expected = 1;
    int reality = 1;
    char arr_num[10] = "0123456789";
    char str1[10] = "aaabbbccce";
    add_num(str1, arr_num, 10);
    for(int i = 0; i < 10; i++){
        if((str1[i] < '0') || (str1[i] > '9')){
            reality = 0;
        }
    }
    ASSERT_EQUAL(expected, reality);
}
CTEST(ctest, NUMBERS2)
{
    int expected = 1;
    int reality = 1;
    char arr_num[10] = "0123456789";
    char str1[10] = "aaabbbccce";
    int len = 10;
    add_num(str1, arr_num, strlen(str1));
    int i = 0;
    while(str1[i]){
        i++;
    }
    if(len != i) reality = 0;
    ASSERT_EQUAL(expected, reality);
}



CTEST(ctest, NOT_NULL_USER_ARGS)
{
    int* arr = args();
    ASSERT_NOT_NULL(arr);
}

CTEST(ctest, NOT_NULL_WORD_LIST)
{
    char** words_array = array_words(count_words);
    ASSERT_NOT_NULL(words_array);
}

CTEST(ctest, NOT_NULL_WORD)
{
    char** words_array = array_words(count_words);
    char* pars = parsmake(words_array, count_words);
    ASSERT_NOT_NULL(pars);
}
