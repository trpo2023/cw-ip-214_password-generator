TARGET = main
TARGET_TEST = main_test
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -MMD
WAY_SOURCE_CODE_FILES = src/libpwgen/
WAY_SOURCE_MAIN = src/pwgen/
WAY_OBJECT_FILES = obj/src/pwgen/
WAY_OBJECT_LIB = obj/src/libpwgen/
WAY_TARGET = bin/
WAY_TARGET_TEST = bin/
WAY_OBJECT_TEST = obj/test/
WAY_SOURCE_CODE_FILE_TEST = test/


SOURCE_CODE_FILES = $(wildcard $(WAY_SOURCE_CODE_FILES)*.c)
OBJECT_CODE_FILES = $(patsubst $(WAY_SOURCE_CODE_FILES)%.c, $(WAY_OBJECT_FILES)%.o, $(SOURCE_CODE_FILES))
SOURCE_MAIN = $(WAY_SOURCE_MAIN)main.c

SOURCE_CODE_FILE_TEST = $(wildcard $(WAY_SOURCE_CODE_FILE_TEST)*.c)
OBJECT_CODE_FILE_TEST = $(patsubst $(WAY_SOURCE_CODE_FILE_TEST)%.c, $(WAY_OBJECT_TEST)%.o, $(SOURCE_CODE_FILE_TEST))

all: clang $(WAY_TARGET_TEST)$(TARGET_TEST) test $(WAY_TARGET)$(TARGET) run clean 

#main
$(WAY_TARGET)$(TARGET) : $(WAY_OBJECT_FILES)main.o $(WAY_OBJECT_LIB)libmy.a
	$(CC) $(CFLAGS) $(OBJECT_CODE_FILES) $(WAY_OBJECT_FILES)main.o -L$(WAY_OBJECT_LIB) -lmy -o $(WAY_TARGET)$(TARGET)

$(WAY_OBJECT_FILES)%.o : $(WAY_SOURCE_CODE_FILES)%.c
	$(CC) -c -I$(WAY_SOURCE_CODE_FILES) $(CFLAGS) $(CPPFLAGS) $< -o $@

$(WAY_OBJECT_FILES)main.o : $(WAY_SOURCE_MAIN)main.c
	$(CC) -c -I$(WAY_SOURCE_CODE_FILES) $(CFLAGS) $(CPPFLAGS) $< -o $@
###

#Lib
$(WAY_OBJECT_LIB)libmy.a : $(OBJECT_CODE_FILES)
	ar rcs $@ $^
###

#test
$(WAY_TARGET_TEST)$(TARGET_TEST) : $(OBJECT_CODE_FILE_TEST) $(WAY_OBJECT_LIB)libmy.a
	$(CC) $(CFLAGS) $(OBJECT_CODE_FILE_TEST) $(WAY_OBJECT_LIB)libmy.a -o $(WAY_TARGET_TEST)$(TARGET_TEST)

$(WAY_OBJECT_TEST)%.o : $(WAY_SOURCE_CODE_FILE_TEST)%.c
	$(CC) -c $(CPPFLAGS) -I$(WAY_SOURCE_CODE_FILES) -I$(WAY_SOURCE_CODE_FILE_TEST) -I thirdparty/ $< -w -o $@
###

clang :
	clang-format -i --verbose $(SOURCE_CODE_FILES) $(WAY_SOURCE_MAIN)main.c

run :
	./$(WAY_TARGET)$(TARGET)

test :
	./$(WAY_TARGET_TEST)$(TARGET_TEST)

clean : 
	rm $(WAY_TARGET)$(TARGET) $(WAY_OBJECT_FILES)*.[od] $(WAY_OBJECT_LIB)*.a $(WAY_OBJECT_TEST)*.[od] $(WAY_TARGET_TEST)$(TARGET_TEST)

.PHONY: clean run test all

-include $(wildcard $(WAY_OBJECT_FILES)*.d) $(wildcard $(WAY_OBJECT_TEST)*.d)