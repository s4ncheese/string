#include "reverse_string.h"

void reverseString(char *string) {
    char *copyS = string;
    printf("\n");
    *reverseCopy(getEndOfString(string) - 1, string - 1, _stringBuffer) = '\0';
    char *beginSource = _stringBuffer;
    WordDescriptor word;
    while (getWord(beginSource, &word)) {
        reverseCopy(word.end, word.begin, string);
        *string = ' ';
        string++;
        beginSource = word.end;
    }

    if (string != copyS) --string;
    *string = '\0';
}

void test_reverseString_emptyString() {
    char string[MAX_STRING_SIZE] = "";
    reverseString(string);
    ASSERT_STRING("", string);
}

void test_reverseString_oneWord() {
    char string[MAX_STRING_SIZE] = "Hello \n";
    reverseString(string);
    ASSERT_STRING("Hello", string);
}

void test_reverseString_notEmptyString() {
    char string[MAX_STRING_SIZE] = "Hello \n world";
    reverseString(string);
    ASSERT_STRING("world Hello", string);
}

void test_reverseString() {
    test_reverseString_emptyString();
    test_reverseString_oneWord();
//    test_reverseString_notEmptyString();
}