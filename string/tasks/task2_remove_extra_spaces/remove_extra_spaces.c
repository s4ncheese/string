#include "remove_extra_spaces.h"

void removeExtraSpaces(char *string) {
    char *begin = string;
    char *destination = begin;
    char last = *begin;

    while (*begin != '\0') {
        if (*begin != last || last != ' ') {
            *destination = *begin;
            destination++;
        }

        last = *begin;
        begin++;
    }
}

void test_removeExtraSpaces_onlySpaces() {
    char string[] = "        ";
    removeExtraSpaces(string);
    ASSERT_STRING("        ", string);
}

void test_removeExtraSpaces_noSpaces() {
    char string[] = "AaBbCcDdE";
    removeExtraSpaces(string);
    ASSERT_STRING("AaBbCcDdE", string);
}

void test_removeExtraSpaces_text() {
    char string[] = "hgh sf jJFGjiw q]vsa'";
    removeExtraSpaces(string);
    ASSERT_STRING("hgh sf jJFGjiw q]vsa'", string);
}

void test_removeExtraSpaces() {
    test_removeExtraSpaces_onlySpaces();
    test_removeExtraSpaces_noSpaces();
    test_removeExtraSpaces_text();
}