#include "amount_palindromes.h"

bool isPoly(WordDescriptor word) {
    word.end--;
    while (word.end > word.begin) {
        if (*word.begin != *word.end)
            return false;

        word.begin++;
        word.end--;
    }

    return true;
}

int amountOfPalindromesInString(char *string) {
    WordDescriptor word;
    int amountOfPoly = 0;
    while (getWord(string, &word)) {
        char *separator = find(word.begin, word.end, ',');
        word.end = separator;
        if (isPoly(word)) amountOfPoly++;
        string = ++word.end;
    }

    return amountOfPoly;
}

void test_amountOfPalindromesInString_emptyString() {
    char string[] = "";
    assert(amountOfPalindromesInString(string) == 0);
}

void test_amountOfPalindromesInString_noPoly() {
    char string[] = "AbC, Cba";
    assert(amountOfPalindromesInString(string) == 0);
}

void test_amountOfPalindromesInString_withPoly() {
    char string[] = "ABBA,AAAA,BAAB,CCAA";
    assert(amountOfPalindromesInString(string) == 3);
}

void test_amountOfPalindromesInString() {
    test_amountOfPalindromesInString_emptyString();
    test_amountOfPalindromesInString_noPoly();
    test_amountOfPalindromesInString_withPoly();
}