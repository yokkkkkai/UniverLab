#include <stdio.h>
#include <stdlib.h>

const char* get_punctuation_abbreviation(char ch) {
    switch (ch) {
    case '.': return "Dot";
    case ',': return "Com";
    case '?': return "Qst";
    case ':': return "Cln";
    case '!': return "Exc";
    default: return NULL;
    }
}

void str_copy(char* dest, const char* src, int len) {
    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
}

char* read_string() {
    int size = 0;
    int capacity = 16;
    char* str = (char*)malloc(capacity * sizeof(char));
    char ch;
    const int abbr_len = 3;

    while ((ch = getchar()) != '\n') {
        const char* abbr = get_punctuation_abbreviation(ch);

        if (abbr != NULL) {
            if (size + abbr_len >= capacity) {
                capacity = capacity * 2;
                char* temp = (char*)malloc(capacity * sizeof(char));

                str_copy(temp, str, size);
                free(str);
                str = temp;
            }

            for (int i = 0; i < abbr_len; i++) {
                str[size++] = abbr[i];
            }
        }
        else {
            if (size + 1 >= capacity) {
                capacity *= 2;
                char* temp = (char*)malloc(capacity * sizeof(char));

                str_copy(temp, str, size);
                free(str);
                str = temp;
            }

            str[size++] = ch;
        }
    }

    str[size] = '\0';
    return str;
}

int is_delimiter(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t';
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
            char** temp = (char**)malloc(capacity * sizeof(char*));

            str_copy((char*)temp, (char*)words, *word_count * sizeof(char*));
            free(words);
            words = temp;
        }

        words[*word_count] = word;
        (*word_count)++;
    }

    return words;
}

int main() {
    printf("Input string: ");
    char* input = read_string();

    int word_count;
    char** words = split_into_words(input, &word_count);

    printf("Result: ");
    for (int i = 0; i < word_count; i++) {
        printf("%s ", words[i]);
        free(words[i]);
    }
    printf("\n");

    free(words);
    free(input);
    return 0;
}
