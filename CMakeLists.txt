cmake_minimum_required(VERSION 3.20)
project(str C)

set(CMAKE_C_STANDARD 11)

add_executable(str main.c
        string/tasks/task4_replace_numbers_with_spaces/replace_numbers_with_spaces.h
        string/tasks/task3_reverse_digit_to_start/reverse_digit_to_start.h
        string/tasks/task2_remove_extra_spaces/remove_extra_spaces.h
        string/tasks/task8_amount_palindromes/amount_palindromes.h
        string/tasks/task6_is_ordered_words/is_ordered_words.h
        string/tasks/task1_delete_spaces/delete_spaces.h
        string/tasks/task5_replace_words/replace_words.h
        string/tasks/task7_bag_of_words/bag_of_words.h
        string/tasks/task7_bag_of_words/bag_of_words.c
        string/tasks/task5_replace_words/replace_words.c
        string/tasks/task1_delete_spaces/delete_spaces.c
        string/tasks/task6_is_ordered_words/is_ordered_words.c
        string/tasks/task8_amount_palindromes/amount_palindromes.c
        string/tasks/task2_remove_extra_spaces/remove_extra_spaces.c
        string/tasks/task3_reverse_digit_to_start/reverse_digit_to_start.c
        string/tasks/task4_replace_numbers_with_spaces/replace_numbers_with_spaces.c
        )

add_library(string string/string_.h string/string_.c)

target_link_libraries(str string)