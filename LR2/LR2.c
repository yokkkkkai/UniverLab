#include <stdio.h>

int main() {
    char inputString[100];
    char symbol = ' ';
    int symbCount = 0, lenTest = 1;

    printf("Enter a string consisting of three words (enter words separated by a space): ");
    while ((symbol = getchar()) != '\n' && symbCount < 99) {
        inputString[symbCount] = symbol;
        symbCount++;
    }

    inputString[symbCount] = '\0';

    for (int i = 3; i < symbCount; i += 4) {
        if (inputString[i] != ' ' && inputString[i] != '\0') {
            printf("ERROR! Word length is 3 symbols");
            lenTest = 0;
            break;
        }
    }
    if (lenTest) {
        char flag[3] = { '\0', '\0', '\0' };

        int wordCnt = 0;

        for (int i = 0; i < symbCount; i++) {
            if (inputString[i] != ' ')
                wordCnt++;
        }

        printf("All words count: %d\n", wordCnt / 3);
        printf("Repeating words: ");
        for (int i = 0; i < symbCount - 4; i += 4) {
            char fSymb = inputString[i], sSymb = inputString[i + 1], tSymb = inputString[i + 2];
            int repeatCount = 1;

            for (int j = i + 4; j < symbCount; j += 4) {
                char jFSymb = inputString[j], jSSymb = inputString[j + 1], jTSymb = inputString[j + 2];
                if ((fSymb == jFSymb) && (sSymb == jSSymb) && (tSymb == jTSymb)) {
                    repeatCount++;
                }
            }

            if (repeatCount > 1 && (fSymb != flag[0] || sSymb != flag[1] || tSymb != flag[2])) {
                printf("%c%c%c (%d times) ", fSymb, sSymb, tSymb, repeatCount);
                flag[0] = fSymb;
                flag[1] = sSymb;
                flag[2] = tSymb;
            }
        }
    }
    return 0;
}

// добавить прговерку длины слова, выводить предупреждение, если не 3
// если ввод корректный - перед ответом вывести общее число слов
// для каждого повторяющегося вывести число повторений
