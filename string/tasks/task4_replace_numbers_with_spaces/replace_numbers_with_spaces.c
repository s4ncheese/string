#include "replace_numbers_with_spaces.h"

void replaceNumbersWithSpaces(char *string) {
    char *endString = getEndOfString(string);
    char *bufIndex = _stringBuffer;
    char *endStringBuf = copy(string, endString, bufIndex);
    *endStringBuf = '\0';
    while (*bufIndex != '\0') {
        if (!isdigit(*bufIndex)) {
            *string = *bufIndex;
            string++;
        } else {
            while (*bufIndex - 48 > 0) {
                *string = ' ';
                string++;
                (*bufIndex)--;
            }
        }

        ++bufIndex;
    }
}

void test_replaceNumbersWithSpaces_emptyString() {
    char string[MAX_STRING_SIZE] = "";
    replaceNumbersWithSpaces(string);
    ASSERT_STRING("", string);
}

void test_replaceNumbersWithSpaces_noDigits() {
    char string[MAX_STRING_SIZE] = "abcdefgh";
    replaceNumbersWithSpaces(string);
    ASSERT_STRING("abcdefgh", string);
}

void test_replaceNumbersWithSpaces_numbers() {
    char string[MAX_STRING_SIZE] = "a12b";
    replaceNumbersWithSpaces(string);
    ASSERT_STRING("a   b", string);
}

void test_replaceNumbersWithSpaces_digits() {
    char string[MAX_STRING_SIZE] = "Hello,1world2!2!2!";
    replaceNumbersWithSpaces(string);
    ASSERT_STRING("Hello, world  !  !  !", string);
}

void test_replaceNumbersWithSpaces() {
    test_replaceNumbersWithSpaces_emptyString();
    test_replaceNumbersWithSpaces_noDigits();
    test_replaceNumbersWithSpaces_numbers();
    test_replaceNumbersWithSpaces_digits();
}