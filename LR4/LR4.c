a#include <stdio.h>

#define MAX_STR_LEN 256
#define MAX_WORDS 50
#define MAX_WORD_LEN 50

//выводить слова в алфавитном порядке (можно по первой букве), при сортировке посчитать количество операций обмпенов слов
//добавить опцию добавления слова с последующей пересортировкой


int strings_are_equal(char* str1, char* str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}

int split_into_words(char* str, char words[][MAX_WORD_LEN]) {
    int word_count = 0;
    char* s = str;
    char* w;

    while (*s) {
        while (*s == ' ' || *s == '\t' || *s == '\n') s++;

        if (*s) {
            w = words[word_count];
            while (*s && *s != ' ' && *s != '\t' && *s != '\n') {
                *w++ = *s++;
            }
            *w = '\0';
            word_count++;
            if (word_count >= MAX_WORDS) break;
        }
    }

    return word_count;
}

void sort_words(char words[][MAX_WORD_LEN], int word_count, int* swap_count) {
    char temp[MAX_WORD_LEN];
    *swap_count = 0;

    for (int i = 0; i < word_count - 1; i++) {
        for (int j = i + 1; j < word_count; j++) {
            char* w1 = words[i], * w2 = words[j];
            while (*w1 == *w2 && *w1) {
                w1++;
                w2++;
            }
            if (*w1 > *w2) {
                for (int k = 0; k < MAX_WORD_LEN; k++) {
                    temp[k] = words[i][k];
                    words[i][k] = words[j][k];
                    words[j][k] = temp[k];
                }
                (*swap_count)++;
            }
        }
    }
}

void count_unique_words(char words[][MAX_WORD_LEN], int word_count, int* swap_count) {
    int counts[MAX_WORDS] = { 0 };
    int processed[MAX_WORDS] = { 0 };

    sort_words(words, word_count, swap_count);

    for (int i = 0; i < word_count; i++) {
        if (*(processed + i)) continue;

        *(counts + i) = 1;
        for (int j = i + 1; j < word_count; j++) {
            if (strings_are_equal(*(words + i), *(words + j))) {
                (*(counts + i))++;
                (*(processed + j)) = 1;
            }
        }
    }

    printf("\nUnique words and their counts: \n");
    for (int i = 0; i < word_count; i++) {
        if (!(*(processed + i))) {
            printf("%s: %d\n", *(words + i), *(counts + i));
        }
    }
}

void add_word(char words[][MAX_WORD_LEN], int* word_count, char* new_word) {
    if (*word_count < MAX_WORDS) {
        int k;
        for (k = 0; new_word[k] && k < MAX_WORD_LEN; k++) {
            words[*word_count][k] = new_word[k];
        }
        words[*word_count][k] = '\0';
        (*word_count)++;
    }
}

int main() {
    char input[MAX_STR_LEN];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int swap_count;

    printf("Input string: ");
    fgets(input, MAX_STR_LEN, stdin);

    int word_count = split_into_words(input, words);

    count_unique_words(words, word_count, &swap_count);
    printf("Number of swaps: %d\n", swap_count);

    char new_word[MAX_WORD_LEN];
    printf("\nEnter a new word to add: ");
    fgets(new_word, MAX_WORD_LEN, stdin);
    int len = 0;

    while (new_word[len] != '\n' && new_word[len] != '\0') 
        len++;

    new_word[len] = '\0';
    add_word(words, &word_count, new_word);

    count_unique_words(words, word_count, &swap_count);
    printf("Number of swaps: %d\n", swap_count);

    return 0;
}
