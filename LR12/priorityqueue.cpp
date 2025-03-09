#include "priorityqueue.h"
#include <stdio.h>
#include <stdlib.h>

PriorityQueue::PriorityQueue() : current_size(0) {
    ptr = (int*)malloc(MAX_SIZE * sizeof(int));
}

PriorityQueue::~PriorityQueue() {
    free(ptr);
}

PriorityQueue::PriorityQueue(const PriorityQueue& other) : current_size(other.current_size) {
    ptr = (int*)malloc(MAX_SIZE * sizeof(int));
    for (int i = 0; i < current_size; ++i) {
        ptr[i] = other.ptr[i];
    }
}

PriorityQueue& PriorityQueue::operator=(const PriorityQueue& other) {
    if (this == &other) {
        return *this;
    }

    free(ptr);
    ptr = (int*)malloc(MAX_SIZE * sizeof(int));
    current_size = other.current_size;

    for (int i = 0; i < current_size; ++i) {
        ptr[i] = other.ptr[i];
    }

    return *this;
}

int PriorityQueue::findPosition(int value) {
    int left = 0;
    int right = current_size - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (ptr[mid] == value) {
            return mid;
        }
        if (ptr[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left;
}

void PriorityQueue::push(int value) {
    if (current_size >= MAX_SIZE) {
        return;
    }

    int index = findPosition(value);

    for (int i = current_size; i > index; i--) {
        ptr[i] = ptr[i - 1];
    }

    ptr[index] = value;
    ++current_size;
}

int PriorityQueue::front() const {
    return (current_size == 0) ? -1 : ptr[0];
}

int PriorityQueue::getSize() const {
    return current_size;
}

void PriorityQueue::print() const {
    for (int i = 0; i < current_size; ++i) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}

void PriorityQueue::setSize(int new_size) {
    if (new_size > 16) {
        return;
    }

    if (new_size < current_size) {
        int* new_ptr = (int*)malloc(MAX_SIZE * sizeof(int));

        for (int i = 0; i < new_size; ++i) {
            new_ptr[i] = ptr[i];
        }

        free(ptr);
        ptr = new_ptr;
        current_size = new_size;
    }
    else if (new_size > current_size) {
        int* new_ptr = (int*)malloc(MAX_SIZE * sizeof(int));

        for (int i = 0; i < current_size; ++i) {
            new_ptr[i] = ptr[i];
        }

        for (int i = current_size; i < new_size; ++i) {
            new_ptr[i] = 0;
        }

        free(ptr);
        ptr = new_ptr;
        current_size = new_size;
    }
}

int* PriorityQueue::getRandom(int x) const {
    if (x > current_size) return NULL;

    int* new_ptr = (int*)malloc(x * sizeof(int));

    int* used = (int*)calloc(16, sizeof(int));
    int cnt = 0;

    while (cnt < x) {
        int index = rand() % current_size;
        if (!used[index]) {
            new_ptr[cnt++] = ptr[index];
            used[index] = true;
        }
    }

    return new_ptr;
}

void PriorityQueue::fillRandom(int x, int min, int max) {
    if (x > MAX_SIZE) return;

    free(ptr);
    ptr = (int*)malloc(MAX_SIZE * sizeof(int));

    int value = 0;

    for (int i = 0; i < x; ++i) {
        value = min + rand() % (max - min + 1);
        push(value);
    }
}