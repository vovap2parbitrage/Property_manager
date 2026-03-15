#pragma once
#include <iostream>
#include <stdexcept>

template <class T>
class list {
    private:
    unsigned size;
    class Node {
        public:
        T data;
        Node* next;
        Node* prev;

        Node(T d) : data(d) , next(nullptr) , prev(nullptr) {} 
    };
    class Iterator {
        private:
        Node* current;

        public:
        Iterator(Node* c) : current(c) {}
        T& operator*() {return current->data; }
        Iterator& operator++() {
            current = current->next; 
            return *this;
        }
        bool operator!=(const Iterator& other) {return current != other.current; }
    };

    Node* head;
    Node* tail;
    public:
    list() : size(0) , head(nullptr) , tail(nullptr) {}

    list(const list& other) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node* current2 = other.head;
        while(current2 != nullptr) {
            push_back(current2->data);
            current2 = current2->next;
        }
    }

    ~list() {
        while(size > 0) {
            pop_back();
        }
    }

    unsigned int getSize() const{return size; }

    Iterator begin() {return head; }
    Iterator end() {return nullptr; }

    void push_back(T d) {
        Node* newNode = new Node(d);
        if(size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        size++;
    }

    void push_front(T d) {
        Node* newNode = new Node(d);
        if(size == 0) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }

        size++;
    }

    void pop_back() {
        if(size == 0) return;
        if(size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }

        size--;
    }

    void pop_front() {
        if(size == 0) return;
        if(size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }

        size--;
    }

    void insert(unsigned int ind , T d) {
        if(size == 0 || ind >= size) {
            push_back(d);
            return;
        }
        if(ind == 0) {
            push_front(d);
            return;
        }
        Node* newNode = new Node(d);
        Node* current = head;
        unsigned int i = 0;
        while(i < ind) {
            current = current->next;
            i++;
        }
        current->prev->next = newNode;
        newNode->prev = current->prev;
        current->prev = newNode;
        newNode->next = current;

        size++;
    }

    T& peek_front() {return head->data; }
    T& peek_back() {return tail->data; }

    T& operator[](unsigned int index) {
        if(index >= size) throw std::out_of_range("Index out of bound");
        Node* current = head;
        for(unsigned int i = 0 ; i < index ; i++) {
            current = current->next;
        }
        return current->data;
    }
};