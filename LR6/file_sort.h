#pragma once

struct Node {
	char* word;
	int vowel_count;
	struct Node* next;
};

int is_vowel(char c);
int count_vowels(const char* word);
int str_len(const char* string);
void str_copy(char* str, const char* src);
int str_compare(const char* str1, const char* str2);
char** split_into_words(const char* str, int* word_count);
struct Node* create_node(const char* word);
void append(struct Node** head, struct Node* new_el);
void vowel_sort(struct Node* head);
void alphabetic_sort(struct Node* head);
void print_list(struct Node* head);
void free_list(struct Node* head);
char* read_file(const char* filename, int* size);
void free_array(char** arr, int size);