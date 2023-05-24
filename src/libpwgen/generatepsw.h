#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gen_psw(int len_pas, int val_pas, int count_words);
void gen_psw_with_word(char* word, int len_pas, int val_pas);
