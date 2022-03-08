#include "string_.h"

void assertString(const char *expected, char *got,
                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp_(expected, got)) {
        fprintf(stderr, " File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, " Expected : \"%s\"\n", expected);
        fprintf(stderr, " Got : \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);

    if (*word->begin == '\0') return 0;
    word->end = findSpace(word->begin);

    return 1;
}

bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->begin = findNonSpaceReverse(rbegin, rend);
    if (word->begin == rend) return false;
    word->end = findSpaceReverse(word->begin, rend);
    return true;
}

size_t strlen_(char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin < end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0') {
        if (isspace(*begin)) return begin;
        begin++;
    }

    return begin;
}

char *findNonSpaceReverse(char *rBegin, const char *rend) {
    while (rBegin > rend) {
        if (!isspace(*rBegin)) return rBegin;
        rBegin--;
    }

    return rBegin;
}

char *findSpaceReverse(char *rBegin, const char *rend) {
    while (rBegin > rend) {
        if (isspace(*rBegin)) return rBegin;
        rBegin--;
    }

    return rBegin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }

    return (unsigned char) *lhs - (unsigned char) *rhs;
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    memcpy(beginDestination, beginSource, endSource - beginSource);

    return beginDestination + (endSource - beginSource);
}

char *reverseCopy(char *rbeginSource, const char *rendSource,
                  char *beginDestination) {
    while (rbeginSource != rendSource) {
        *beginDestination++ = *rbeginSource;
        rbeginSource--;
    }
    return beginDestination;
}

int isNonSpace(int symbol) {
    return !isspace(symbol) ? 1 : 0;
}

char *copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }

        beginSource++;
    }

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (rbeginSource > rendSource) {
        if (f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }

        rbeginSource--;
    }

    return beginDestination;
}

char *getEndOfString(char *s) {
    while (*s != '\0')
        s++;

    return s;
}

void getBagOfWords(BagOfWords *bag, char *string) {
    bag->size = 0;
    WordDescriptor word;
    while (getWord(string, &word)) {
        bag->words[bag->size] = word;
        bag->size++;
        string = word.end;
    }
}
