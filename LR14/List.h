#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>
#include "Node.h"

template <typename T>
class List {
private:
    Node<T>* head;
    size_t size;

public:
    List() : head(nullptr), size(0) {}

    List(const List<T>& other);
    List<T>& operator=(const List<T>& other);
    ~List();

    T& operator[] (size_t index);

    friend std::ostream& operator<<(std::ostream& out, const List<T>& list);
    friend std::istream& operator>>(std::istream& in, List<T>& list);

    List(std::initializer_list<T> init);

    void append(T data);
    void push_front(T data);
    void pop();
    void pop_back();
    void remove(T data);
    void print();
    size_t get_size() const;
};

// Реализация конструктора копирования
template <typename T>
List<T>::List(const List<T>& other) : head(nullptr), size(0) {
    Node<T>* current = other.head;
    while (current) {
        append(current->data);
        current = current->next;
    }
}

// Реализация оператора присваивания
template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this == &other) {
        return *this;
    }

    Node<T>* current = head;
    while (current) {
        Node<T>* tmp = current;
        current = current->next;
        delete tmp;
    }

    head = nullptr;
    size = 0;
    current = other.head;

    while (current) {
        append(current->data);
        current = current->next;
    }

    return *this;
}

// Реализация деструктора
template <typename T>
List<T>::~List() {
    Node<T>* current = head;
    while (current) {
        Node<T>* tmp = current;
        current = current->next;
        delete tmp;
    }
}

// Реализация оператора индексации
template <typename T>
T& List<T>::operator[] (size_t index) {
    if (index >= size) {
        std::cerr << "Index out of range" << std::endl;
        throw std::out_of_range("Index out of range");
    }

    Node<T>* current = head;
    for (size_t i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// Реализация конструктора с инициализационным списком
template <typename T>
List<T>::List(std::initializer_list<T> init) : head(nullptr), size(0) {
    for (const T& value : init) {
        append(value);
    }
}

// Реализация методов для добавления и удаления элементов
template <typename T>
void List<T>::append(T data) {
    Node<T>* new_node = new Node<T>(data);

    if (!head) {
        head = new_node;
    }
    else {
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_node;
    }
    size++;
}

template <typename T>
void List<T>::push_front(T data) {
    Node<T>* new_node = new Node<T>(data);

    if (!head) {
        head = new_node;
    }
    else {
        new_node->next = head;
        head = new_node;
    }
    size++;
}

template <typename T>
void List<T>::pop() {
    if (!head) {
        std::cerr << "Error: List is empty, cannot pop the first element." << std::endl;
        return;
    }

    Node<T>* tmp = head;
    head = head->next;
    delete tmp;
    size--;
}

template <typename T>
void List<T>::pop_back() {
    if (!head) {
        std::cerr << "Error: List is empty, cannot pop the last element." << std::endl;
        return;
    }

    if (!head->next) {
        delete head;
        head = nullptr;
        size = 0;
        return;
    }

    Node<T>* current = head;
    while (current->next && current->next->next) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
    size--;
}

template <typename T>
void List<T>::remove(T data) {
    if (!head) {
        std::cerr << "Error: List is empty, cannot remove element." << std::endl;
        return;
    }

    if (head->data == data) {
        pop();
        return;
    }

    Node<T>* current = head;
    while (current->next && current->next->data != data) {
        current = current->next;
    }

    if (!current->next) {
        std::cerr << "Error: Element " << data << " not found in the list." << std::endl;
        return;
    }

    Node<T>* tmp = current->next;
    current->next = current->next->next;
    delete tmp;
    size--;
}

template <typename T>
void List<T>::print() {
    if (!head) {
        std::cerr << "Error: List is empty, nothing to print." << std::endl;
        return;
    }

    Node<T>* current = head;
    while (current) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

template <typename T>
size_t List<T>::get_size() const {
    return size;
}

// Реализация операторов ввода-вывода
template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& list) {
    Node<T>* current = list.head;
    while (current) {
        out << current->data << std::endl;
        current = current->next;
    }
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, List<T>& list) {
    T value;
    in >> value;
    if (in) {
        list.append(value);
    }

    return in;
}

#endif // LIST_H
