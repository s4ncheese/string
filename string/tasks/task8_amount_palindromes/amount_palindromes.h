#ifndef STR_AMOUNT_PALINDROMES_H
#define STR_AMOUNT_PALINDROMES_H

#include "../../string_.h"

bool isPoly(WordDescriptor word);

int amountOfPalindromesInString(char *string);

void test_amountOfPalindromesInString_emptyString();

void test_amountOfPalindromesInString_noPoly();

void test_amountOfPalindromesInString_withPoly();

void test_amountOfPalindromesInString();

#endif //STR_AMOUNT_PALINDROMES_H
