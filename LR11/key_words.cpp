#include <iostream>
#include <fstream>

int str_len(const char* s) {
    int cnt = 0;
    while (*s != '\0') {
        cnt++;
        s++;
    }

    return cnt;
}

void str_copy(char* str, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }

    str[i] = '\0';
}

bool str_equal(const char* s1, const char* s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) return false;

        s1++;
        s2++;
    }

    return (*s1 == '\0' && *s2 == '\0');
}

bool is_delimiter(const char c) {
    char delimiters[] = " \t\n,.;(){}[]+-*/=&|<>!?:\"\'";
    int i = 0;
    while (delimiters[i] != '\0') {
        if (c == delimiters[i]) return true;
        i++;
    }

    return false;
}

char* find_keyword(char* line) {
    const char* keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union",
        "unsigned", "void", "volatile", "while"
    };
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);

    int i = 0;
    while (line[i] != '\0') {
        while (line[i] != '\0' && is_delimiter(line[i])) {
            i++;
        }

        int word_start = i;

        while (line[i] != '\0' && !is_delimiter(line[i])) {
            i++;
        }

        char temp = line[i];
        line[i] = '\0';

        for (int j = 0; j < num_keywords; j++) {
            if (str_equal(&line[word_start], keywords[j])) {
                return &line[word_start];
            }
        }

        line[i] = temp;
    }

    return NULL;
}