#pragma once

int is_delimiter(char ch);
void str_copy(char* dest, const char* src, int length);
int str_len(const char* str);
char** split_into_words(const char* str, int* word_count);
void trim_string(char* str);
void format_text(const char* input_file, const char* output_file);