#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "file_sort.h"

int is_vowel(char c) {
	if (c >= 'A' && c <= 'Z') c = c + ('a' - 'A');
	return (c == 'a' || c == 'e' || c == 'i' ||
		c == 'o' || c == 'u' || c == 'y');
}

int count_vowels(const char* word) {
	int cnt = 0;
	while (*word != '\0') {
		if (is_vowel(*word))
			cnt++;
		word++;
	}
	return cnt;
}

int str_len(const char* string) {
	int cnt = 0;
	while (*string != '\0') {
		cnt++;
		string++;
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

int str_compare(const char* str1, const char* str2) {
	while (*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2) return -1;
		if (*str1 > *str2) return 1;
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0') return 0;
	if (*str1 == '\0') return -1;
	return 1;
}

char** split_into_words(const char* str, int* word_count) {
	*word_count = 0;
	int capacity = 8;
	char** words = (char**)malloc(capacity * sizeof(char*));
	int pos = 0;

	while (str[pos] != '\0') {
		while (str[pos] == ' ' || str[pos] == '\n' || str[pos] == '\t') pos++;
		if (str[pos] == '\0') break;

		int start = pos;
		while (str[pos] != ' ' && str[pos] != '\n' && str[pos] != '\t' && str[pos] != '\0') {
			pos++;
		}

		int length = pos - start;
		char* word = (char*)malloc((length + 1) * sizeof(char));

		for (int i = 0; i < length; i++) {
			word[i] = str[start + i];
		}
		word[length] = '\0';

		if (*word_count >= capacity) {
			capacity *= 2;
			char** temp = (char**)malloc(capacity * sizeof(char*));
			for (int i = 0; i < *word_count; i++) {
				temp[i] = words[i];
			}
			free(words);
			words = temp;
		}

		words[*word_count] = word;
		(*word_count)++;
	}
	return words;
}

struct Node* create_node(const char* word) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->word = (char*)malloc(str_len(word) + 1);
	str_copy(node->word, word);
	node->vowel_count = count_vowels(word);
	node->next = NULL;
	return node;
}

void append(struct Node** head, struct Node* new_el) {
	if (*head == NULL) {
		*head = new_el;
		return;
	}
	struct Node* tmp = *head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = new_el;
}

void vowel_sort(struct Node* head) {
	if (head == NULL || head->next == NULL) return;

	int swap;
	struct Node* ptr;
	struct Node* last_sorted = NULL;

	do {
		swap = 0;
		ptr = head;

		while (ptr->next != last_sorted) {
			if (ptr->vowel_count > ptr->next->vowel_count) {
				char* tmp_word = ptr->word;
				int tmp_count = ptr->vowel_count;

				ptr->word = ptr->next->word;
				ptr->vowel_count = ptr->next->vowel_count;

				ptr->next->word = tmp_word;
				ptr->next->vowel_count = tmp_count;

				swap = 1;
			}
			ptr = ptr->next;
		}
		last_sorted = ptr;
	} while (swap);
}

void alphabetic_sort(struct Node* head) {
	if (head == NULL || head->next == NULL) {
		return;
	}

	int swap;
	struct Node* ptr;
	struct Node* last_sorted = NULL;

	do {
		swap = 0;
		ptr = head;

		while (ptr->next != last_sorted) {
			if (ptr->next == NULL) break;

			if (str_compare(ptr->word, ptr->next->word) > 0) {
				char* tmp_word = ptr->word;
				int tmp_count = ptr->vowel_count;

				ptr->word = ptr->next->word;
				ptr->vowel_count = ptr->next->vowel_count;

				ptr->next->word = tmp_word;
				ptr->next->vowel_count = tmp_count;

				swap = 1;
			}
			ptr = ptr->next;
		}
		last_sorted = ptr;
	} while (swap);
}

void print_list(struct Node* head) {
	while (head != NULL) {
		printf("%s ", head->word);
		head = head->next;
	}
	printf("\n");
}

void free_list(struct Node* head) {
	struct Node* current = head;
	struct Node* next;

	while (current != NULL) {
		next = current->next;
		free(current->word);
		free(current);
		current = next;
	}
}

char* read_file(const char* filename, int* size) {
	FILE* file = fopen(filename, "r");

	if (file == NULL) {
		printf("Error! File not open!\n");
		return NULL;
	}

	int capacity = 16;
	int index = 0;
	char* buffer = (char*)malloc(capacity * sizeof(char));
	char line[256];

	while (fgets(line, sizeof(line), file)) {
		int line_len = str_len(line);
		if (index + line_len >= capacity) {
			capacity *= 2;
			char* new_buffer = (char*)malloc(capacity * sizeof(char));
			for (int i = 0; i < index; i++) {
				new_buffer[i] = buffer[i];
			}
			free(buffer);
			buffer = new_buffer;
		}
		for (int i = 0; i < line_len; i++) {
			buffer[index++] = line[i];
		}
	}

	buffer[index] = '\0';
	*size = index;
	fclose(file);
	return buffer;
}


void free_array(char** arr, int size) {
	for (int i = 0; i < size; i++) {
		free(arr[i]);
	}
	free(arr);
}