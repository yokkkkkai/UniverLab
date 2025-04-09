#include <stdio.h>
#include <stdlib.h>
#include "file_sort.h"

int main() {
	int file_size;
	char* file_str = read_file("file.txt", &file_size);

	printf("%s\n", file_str);

	int words_array_size;
	char** words_array = split_into_words(file_str, &words_array_size);

	for (int i = 0; i < words_array_size; i++) {
		printf("%s ", words_array[i]);
	}
	printf("\n");

	struct Node* vowel_head = NULL;
	struct Node* alphabet_head = NULL;

	for (int i = 0; i < words_array_size; i++) {
		struct Node* new_vowel_node = create_node(words_array[i]);
		struct Node* new_alphabet_node = create_node(words_array[i]);

		append(&vowel_head, new_vowel_node);
		append(&alphabet_head, new_alphabet_node);
	}

	vowel_sort(vowel_head);
	print_list(vowel_head);

	alphabetic_sort(alphabet_head);
	print_list(alphabet_head);

	free_list(alphabet_head);
	free_list(vowel_head);
	free_array(words_array, words_array_size);
	free(file_str);
	return 0;
}
