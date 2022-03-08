#ifndef STR_STRING_H
#define STR_STRING_H

#include <stdlib.h>
#include <ctype.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char _stringBuffer[MAX_STRING_SIZE + 1];

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line);

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа слова
} WordDescriptor;

int getWord(char *beginSearch, WordDescriptor *word);

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

size_t strlen_(char *begin);

char *find(char *begin, char *end, int ch);

char *findNonSpace(char *begin);

char *findSpace(char *begin);

char *findNonSpaceReverse(char *rBegin, const char *rend);

char *findSpaceReverse(char *rBegin, const char *rend);

int strcmp_(const char *lhs, const char *rhs);

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

int isNonSpace(int symbol);

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

char *getEndOfString(char *s);


#endif //STR_STRING_H