#include "priorityqueue.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main() {
    srand(time(NULL));

    PriorityQueue pq1;
    PriorityQueue pq2;
    PriorityQueue pq3;
    PriorityQueue pqMax;

    pqMax.fillRandom(16, 1, 10);

    pqMax.push(17);
    pqMax.push(18);

    printf("Overflowing array: ");
    pqMax.print();

    printf("Random queue: ");
    pq3.fillRandom(6, 10, 111);
    pq3.print();

    pq1.push(1);
    pq1.push(5);
    pq1.push(2);

    printf("pq1: ");
    pq1.print();

    printf("pq1 front: ");
    int pq1_el = pq1.front();
    printf("%d\n", pq1_el);

    pq2 = pq1;

    printf("pq2: ");
    pq2.print();

    printf("pq2 front: ");
    int pq2_el = pq2.front();
    printf("%d\n", pq2_el);


    pq1.setSize(16);
    printf("New pq1(set size up): ");
    pq1.print();

    pq2.setSize(2);
    printf("New pq2(set size down): ");
    pq2.print();

    int* array = pq3.getRandom(5);
    printf("Random elements from array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

// реализовать заполнение и взятие X случайных значений (x - пользовательское)
// в т.ч. показать работу при переполнении
// функция setSize устанавливает размер и добавляет нулевые элементы, если надо (иначе удаляет)
