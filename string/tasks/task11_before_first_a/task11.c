#include "task11.h"

void printWord(WordDescriptor word) {
    while (word.begin != word.end) {
        printf("%c", *word.begin);
        word.begin++;
    }

    printf(" ");
}

void printWordBeforeFirstWordWithA(char *s) {
    char *begin = s;
    char *end = getEndOfString(s);
    WordDescriptor prev;
    WordDescriptor word;
    getWord(begin, &prev);

    if (!getWord(begin, &prev))
        printf("Empty string\n");

    else if (find(begin, end, 'a') == end && find(begin, end, 'A') == end)
        printf ("No words with \"a\"");

    else if (*prev.begin != '\0' && (find(prev.begin, prev.end, 'a') == end
                                  || find(prev.begin, prev.end, 'A') == end)) {
        printf("First word is include \"a\"");
    }

    else {
        while (getWord(begin, &word)) {
            if (find(prev.begin, prev.end, 'a') || find(prev.begin, prev.end, 'A')) {
                printWord(prev);
                break;
            } else {
                prev.begin = word.begin;
                prev.end = word.end;
            }
        }
    }

}

void test_printWordBeforeFirstWordWithA_emptyString() {
    char string[] = "";
    printWordBeforeFirstWordWithA(string);
    printf("\n");
}

void test_printWordBeforeFirstWordWithA_noWordsWithA() {
    char string[] = "BbbbBb bddgsfhf, fllds \n df";
    printWordBeforeFirstWordWithA(string);
    printf("\n");
}

void test_printWordBeforeFirstWordWithA_firstWithA() {
    char string[] = "gaffff \t fks bad";
    printWordBeforeFirstWordWithA(string);
    printf("\n");
}

void test_printWordBeforeFirstWordWithA_beforeWordWithA() {
    char string[] = "John Watson";
    printWordBeforeFirstWordWithA(string);
    printf("\n");
}

void test_printWordBeforeFirstWordWithA() {
    test_printWordBeforeFirstWordWithA_emptyString();
    test_printWordBeforeFirstWordWithA_noWordsWithA();
    test_printWordBeforeFirstWordWithA_firstWithA();
    test_printWordBeforeFirstWordWithA_beforeWordWithA();
}