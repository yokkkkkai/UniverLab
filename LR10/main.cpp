#include <stdio.h>
#include <stdlib.h>
#include "format_file.h"

int main() {
    char input_file[256] = "input.txt";
    char output_file[256] = "output.txt";

    format_text(input_file, output_file);

    return 0;
}
