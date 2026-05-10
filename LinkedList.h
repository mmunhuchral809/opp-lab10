#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

// Template холбоот жагсаалтын класс
// T - ямар ч төрлийн өгөгдөл хадгалах боломжтой
template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Эхний зангилаа руу заах pointer
    int size;       // Одоогийн элементийн тоо

public:
    // Байгуулагч: хоосон жагсаалт үүсгэнэ
    LinkedList() : head(nullptr), size(0) {}

    // Сүүлд элемент нэмнэ
    void add(T t) {
        Node<T>* newNode = new Node<T>(t);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* curr = head;
            while (curr->next != nullptr)
                curr = curr->next;
            curr->next = newNode;
        }
        size++;
    }

    // Заасан index-т элемент оруулна
    void insert(T t, int index) {
        if (index < 0 || index > size) {
            cout << "Invalid index!" << endl;
            return;
        }
        Node<T>* newNode = new Node<T>(t);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* curr = head;
            for (int i = 0; i < index - 1; i++)
                curr = curr->next;
            newNode->next = curr->next;
            curr->next = newNode;
        }
        size++;
    }

    // index дүгээр элементийг буцаана
    T get(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return T();
        }
        Node<T>* curr = head;
        for (int i = 0; i < index; i++)
            curr = curr->next;
        return curr->data;
    }

    // index дүгээр элементийг устгана
    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            return;
        }
        Node<T>* toDelete;
        if (index == 0) {
            toDelete = head;
            head = head->next;
        } else {
            Node<T>* curr = head;
            for (int i = 0; i < index - 1; i++)
                curr = curr->next;
            toDelete = curr->next;
            curr->next = toDelete->next;
        }
        delete toDelete;
        size--;
    }

    // Жагсаалтын уртыг буцаана
    int length() {
        return size;
    }

    // Талбайгаар өсөхөөр эрэмбэлнэ (bubble sort)
    // Shape* төрлийн жагсаалтад ашиглана
    void sortByArea() {
        if (size <= 1) return;
        bool swapped;
        do {
            swapped = false;
            Node<T>* curr = head;
            while (curr->next != nullptr) {
                if (curr->data->area() > curr->next->data->area()) {
                    T temp = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = temp;
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
    }

    // Бүх элементийг хэвлэнэ
    void printAll() {
        Node<T>* curr = head;
        int i = 0;
        while (curr != nullptr) {
            cout << "[" << i++ << "] ";
            curr->data->print();
            cout << endl;
            curr = curr->next;
        }
    }

    // Деструктор: бүх node-ийн санах ойг чөлөөлнө
    ~LinkedList() {
        Node<T>* curr = head;
        while (curr != nullptr) {
            Node<T>* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};