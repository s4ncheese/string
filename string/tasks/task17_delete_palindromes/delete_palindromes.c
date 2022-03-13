#include "delete_palindromes.h"

void deletePalindromes(char *string) {
    char *endSource = getEndOfString(string);
    *copy(string, endSource, _stringBuffer) = '\0';
    WordDescriptor word;
    char *beginBuf = _stringBuffer;
    while (getWord(beginBuf, &word)) {
        while (isspace(*beginBuf)) {
            copy(beginBuf, beginBuf + 1, string);
            beginBuf++;
            string++;
        }
        if (isPoly(word)) {
            beginBuf = word.end;
        } else {
            copy(word.begin, word.end, string);
            beginBuf = word.end;
            string += word.end - word.begin;
        }
    }
    *string = '\0';
}

void test_deletePalindromes_emptyString() {
    char string[] = "";
    deletePalindromes(string);
    ASSERT_STRING("", string);
}

void test_deletePalindromes_noPoli() {
    char string[] = "Asdffdf \tppgfsdd ;lmflmb;";
    deletePalindromes(string);
    ASSERT_STRING("Asdffdf \tppgfsdd ;lmflmb;", string);
}

void test_deletePalindromes_withPoli1() {
    char string[] = "Asdffdf \tppgfsdd ;asa; dff pPpoOopPp";
    deletePalindromes(string);
    ASSERT_STRING("Asdffdf \tppgfsdd  dff ", string);
}

void test_deletePalindromes_withPoli2() {
    char string[] = "\t AfA ";
    deletePalindromes(string);
    ASSERT_STRING("\t ", string);
}

void test_deletePalindromes() {
    test_deletePalindromes_emptyString();
    test_deletePalindromes_noPoli();
    test_deletePalindromes_withPoli1();
    test_deletePalindromes_withPoli2();
}