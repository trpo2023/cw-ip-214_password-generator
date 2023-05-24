#pragma once
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void pass_string(char**, int, int);
char* edit_string(char*, int);
void add_num(char*, char*, int);
void insert_word(char*, char*, int, int);
void add_special(char*, char*, int);
void display_password(char*);
extern char full_pass[256];