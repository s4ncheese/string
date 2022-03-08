#ifndef STR_IS_ORDERED_WORDS_H
#define STR_IS_ORDERED_WORDS_H

#include "../../string_.h"

int areWordsEqual(WordDescriptor w1, WordDescriptor w2);

bool isOrderedWords(char *string);

void test_isOrderedWords_emptyString();

void test_isOrderedWords_notOrdered();

void test_isOrderedWords_ordered();

void test_isOrderedWords();

void test_areWordsEqual_equal();

void test_areWordsEqual_notEqual();

void test_areWordsEqual();

#endif //STR_IS_ORDERED_WORDS_H
