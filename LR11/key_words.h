#pragma once

int str_len(const char* s);
void str_copy(char* str, const char* src);
bool is_equal(const char* s1, const char* s2);
bool is_delimiter(const char c);
char* find_keyword(char* line);