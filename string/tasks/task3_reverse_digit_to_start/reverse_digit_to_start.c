#include "reverse_digit_to_start.h"

void digitToStartReverse(WordDescriptor word)  {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartWithSaveOrderInWord(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPos = copyIf(_stringBuffer, endStringBuffer,
                          word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPos, isalpha);
}

void digitToStartInString(char *string) {
    char *beginSearch = string;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithSaveOrderInWord(word);
        beginSearch = word.end;
    }
}

void test_digitToStartInString_noWords() {
    char string[] = "\t \n   ";
    digitToStartInString(string);
    ASSERT_STRING("\t \n   ", string);
}

void test_digitToStartInString_digits() {
    char string[] = "12312 3123";
    digitToStartInString(string);
    ASSERT_STRING("12312 3123", string);
}

void test_digitToStartInString_digitsAndLetters() {
    char string[] = "Qwertyuiop12312";
    digitToStartInString(string);
    ASSERT_STRING("12312Qwertyuiop", string);
}

void test_digitToStartInString_wordsWithSpaces() {
    char string[] = "Hel2lo 1\t1 wor1ld23";
    digitToStartInString(string);
    ASSERT_STRING("2Hello 1\t1 123world", string);
}

void test_digitToStartInString() {
    test_digitToStartInString_noWords();
    test_digitToStartInString_digits();
    test_digitToStartInString_digitsAndLetters();
    test_digitToStartInString_wordsWithSpaces();
}