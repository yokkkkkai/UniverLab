#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int prime(int n) {
    if (n < 2)
        return 0;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void populateAnArray(int* array, int operation, int arraySize) {
    int cnt, index = 0;

    if (operation == 1) {
        cnt = 0;
        while (index != arraySize) {
            array[index] = cnt;
            cnt += 2;
            index++;
        }
    }
    else if (operation == 2) {
        cnt = 1;
        while (index != arraySize) {
            array[index] = cnt;
            cnt += 2;
            index++;
        }
    }
    else if (operation == 3) {
        cnt = 2;
        while (index != arraySize) {
            if (prime(cnt)) {
                array[index] = cnt;
                index++;
            }
            cnt++;
        }
    }
    else if (operation == 4) {
        srand(time(0));
        for (int i = 0; i < arraySize; i++)
            array[i] = rand();
    }
}

void changeElement(int* array, int size, int newElement, int elIndex) {
    for (int i = size - 1; i > elIndex; i--) {
        array[i] = array[i - 1];
    }
    array[elIndex] = newElement;
}

int main() {
    int operation;
    printf("Choose operation (1 - even, 2 - odd, 3 - prime, 4 - random): ");
    scanf("%d", &operation);

    int array[ARRAY_SIZE] = { 0 };
    populateAnArray(array, operation, ARRAY_SIZE);

    int newElement = 0;
    int newElIndex = 0;

    printf("Enter new element: ");
    scanf("%d", &newElement);

    printf("Enter new element index: ");
    scanf("%d", &newElIndex);

    changeElement(array, ARRAY_SIZE, newElement, newElIndex);

    for (int i = 0; i < ARRAY_SIZE; i++)
        printf("%d ", array[i]);

    return 0;
}


// написать ф-ю для заполнения массива в соответствии с выбранным пользователем условием (напр, 1 : 1 2 3 4..., 2: 10 9 8 7, 3: случайные числа) - придумать 4 опции
