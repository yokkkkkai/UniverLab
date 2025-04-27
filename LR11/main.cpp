#include <fstream>
#include <iostream>
#include "key_words.h"

int main() {
    const char filename[] = "file.txt";
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "File not open!";
    }

    char line[1024];
    int line_num = 0;

    while (file.getline(line, sizeof(line))) {
        char line_copy[1000];
        str_copy(line_copy, line);

        char* keyword = find_keyword(line_copy);

        std::cout << (keyword == NULL ? "0" : keyword) << std::endl;
    }


    return 0;
}
