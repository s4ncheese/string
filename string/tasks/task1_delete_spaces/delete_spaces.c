#include "delete_spaces.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_noLetters() {
    char string[] = " ";
    removeNonLetters(string);
    char answerString[] = "";

    ASSERT_STRING(answerString, string);
}

void test_removeNonLetters_oneWord() {
    char string[] = "Hi";
    removeNonLetters(string);
    char answerString[] = "Hi";

    ASSERT_STRING(answerString, string);
}

void test_removeNonLetters_threeWords() {
    char string[] = "H i 1 2 3";
    removeNonLetters(string);
    char answerString[] = "Hi123";

    ASSERT_STRING(answerString, string);
}

void test_removeNonLetters() {
    test_removeNonLetters_noLetters();
    test_removeNonLetters_oneWord();
    test_removeNonLetters_threeWords();
}