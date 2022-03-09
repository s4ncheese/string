#include "merge_strings.h"

char *alternatelyMergeStrings(char *s1, char *s2, char *string) {
    WordDescriptor w1, w2;
    bool isW1Found, isW2Found;
    char *sCopy = string;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &w1)),
            (isW2Found = getWord(beginSearch2, &w2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            string = copy(w1.begin, w1.end, string);
            *string = ' ';
            string++;
            beginSearch1 = w1.end;
        }
        if (isW2Found) {
            string = copy(w2.begin, w2.end, string);
            *string = ' ';
            string++;
            beginSearch2 = w2.end;
        }
    }
    if (string != sCopy)
        string--;
    *string = '\0';
    return sCopy;
}

void test_alternatelyMergeStrings_emptyStrings() {
    char s1[] = "";
    char s2[] = "";
    char ansString[MAX_STRING_SIZE];

    ASSERT_STRING("", alternatelyMergeStrings(s1, s2, ansString));
}

void test_alternatelyMergeStrings_firstEmpty() {
    char s1[] = "";
    char s2[] = "dfsf \t asd";
    char ansString[MAX_STRING_SIZE];

    ASSERT_STRING("dfsf asd", alternatelyMergeStrings(
            s1, s2, ansString));
}

void test_alternatelyMergeStrings_secondEmpty() {
    char s1[] = "ldfkgsi \n af 0";
    char s2[] = "";
    char ansString[MAX_STRING_SIZE];

    ASSERT_STRING("ldfkgsi af 0", alternatelyMergeStrings(
            s1, s2, ansString));
}

void test_alternatelyMergeStrings_notEmpty() {
    char s1[] = "I'm dabudi dabudi dabudi";
    char s2[] = "blue dabudai dabudai dabudai";
    char ansString[MAX_STRING_SIZE];

    ASSERT_STRING("I'm blue dabudi dabudai dabudi dabudai"
                  " dabudi dabudai", alternatelyMergeStrings(
            s1, s2, ansString));
}

void test_alternatelyMergeStrings() {
    test_alternatelyMergeStrings_emptyStrings();
    test_alternatelyMergeStrings_firstEmpty();
    test_alternatelyMergeStrings_secondEmpty();
    test_alternatelyMergeStrings_notEmpty();
}