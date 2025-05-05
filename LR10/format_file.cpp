#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "format_file.h"

int is_delimiter(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t';
}

void str_copy(char* dest, const char* src, int length) {
    for (int i = 0; i < length; i++) {
        dest[i] = src[i];
    }
}

int str_len(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char** split_into_words(const char* str, int* word_count) {
    *word_count = 0;
    int capacity = 8;
    char** words = (char**)malloc(capacity * sizeof(char*));
    int pos = 0;

    while (str[pos] != '\0') {
        while (is_delimiter(str[pos])) {
            pos++;
            if (str[pos] == '\0') break;
        }
        if (str[pos] == '\0') break;

        int start = pos;

        while (!is_delimiter(str[pos]) && str[pos] != '\0') {
            pos++;
        }

        int length = pos - start;

        char* word = (char*)malloc((length + 1) * sizeof(char));

        str_copy(word, str + start, length);
        word[length] = '\0';

        if (*word_count >= capacity) {
            capacity *= 2;
            char** temp = (char**)realloc(words, capacity * sizeof(char*));
            words = temp;
        }

        words[*word_count] = word;
        (*word_count)++;
    }

    return words;
}

void trim_string(char* str) {
    int i = 0, j = 0;
    while (str[i] != '\0' && is_delimiter(str[i])) {
        i++;
    }
    while (str[i] != '\0') {
        str[j++] = str[i++];
    }
    str[j] = '\0';
    j = j - 1;
    while (j >= 0 && is_delimiter(str[j])) {
        str[j--] = '\0';
    }
}

void format_text(const char* input_file, const char* output_file) {
    FILE* fin, * fout;
    char line[1000];
    char formatted_line[1000];

    fin = fopen(input_file, "r");
    fout = fopen(output_file, "w");

    while (fgets(line, sizeof(line), fin) != NULL) {
        int len = str_len(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        trim_string(line);

        if (line[0] == '\0') {
            fprintf(fout, "\n");
            continue;
        }

        int word_count = 0;
        char** words = split_into_words(line, &word_count);

        int i;
        for (i = 0; i < 1000; i++) {
            formatted_line[i] = '\0';
        }

        int total_words_length = 0;
        for (i = 0; i < word_count; i++) {
            total_words_length += str_len(words[i]);
        }

        for (i = 0; i < 2; i++) {
            formatted_line[i] = ' ';
        }

        int available_space = 60 - 3 - total_words_length;

        int spaces_between = (word_count - 1 > 0) ? (available_space / (word_count - 1)) : 0;
        int extra_spaces = (word_count - 1 > 0) ? (available_space % (word_count - 1)) : 0;

        int current_pos = 2;
        for (i = 0; i < word_count; i++) {
            int word_length = str_len(words[i]);
            int j;
            for (j = 0; j < word_length; j++) {
                formatted_line[current_pos++] = words[i][j];
            }
            if (i < word_count - 1) {
                int spaces = spaces_between + (i < extra_spaces ? 1 : 0);
                for (j = 0; j < spaces; j++) {
                    formatted_line[current_pos++] = ' ';
                }
            }
        }
        formatted_line[current_pos] = '\0';

        fprintf(fout, "%s\n", formatted_line);

        for (i = 0; i < word_count; i++) {
            free(words[i]);
        }
        free(words);
    }

    fclose(fin);
    fclose(fout);
    printf("Formatting is complete.\n");
}
