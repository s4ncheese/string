#include "is_ordered_words.h"

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    if (w2.end - w2.begin != w1.end - w1.begin)
        return 0;
    while (w1.begin < w1.end) {
        if (w1.begin < w2.begin)
            return 0;
        w1.begin++;
    }

    return 1;
}

bool isOrderedWords(char *string) {
    WordDescriptor word1, word2;
    if (getWord(string, &word1)) {
        word2 = word1;
        while (getWord(string, &word1)) {
            if (strcmp_(word1.begin, word2.begin) < 0)
                return false;

            word2 = word1;
            string = word1.end;
        }
    }

    return true;
}

void test_areWordsEqual_equal() {
    char string1[] = "HjKl";
    char string2[] = "HjKl";
    WordDescriptor w1 = {string1, string1 + strlen_(string1)};
    WordDescriptor w2 = {string2, string2 + strlen_(string2)};
    assert(areWordsEqual(w1, w2) == 1);
}

void test_areWordsEqual_notEqual() {
    char string1[] = "HjKl1";
    char string2[] = "HjKl";
    WordDescriptor w1 = {string1, string1 + strlen_(string1)};
    WordDescriptor w2 = {string2, string2 + strlen_(string2)};
    assert(areWordsEqual(w1, w2) == 0);
}

void test_areWordsEqual() {
    test_areWordsEqual_equal();
    test_areWordsEqual_notEqual();
}

void test_isOrderedWords_emptyString() {
    char string[] = "";
    assert(isOrderedWords(string) == true);
}

void test_isOrderedWords_notOrdered() {
    char string[] = "max mad";
    assert(isOrderedWords(string) == false);
}

void test_isOrderedWords_ordered() {
    char string[] = "AAA bbb";
    assert(isOrderedWords(string) == true);
}

void test_isOrderedWords() {
    test_isOrderedWords_emptyString();
    test_isOrderedWords_notOrdered();
    test_isOrderedWords_ordered();
}
