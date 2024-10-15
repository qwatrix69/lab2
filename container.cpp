#include "container.h"

Container::Container() : head(nullptr), tail(nullptr), count(0) {cout << "Вызван конструктор без параметров для класса Container";}

Container::Container(Node* h, Node* t, const int c) : head(h), tail(t), count(c) {
    cout << "Вызван конструктор с параметрами для класса Container";
}

Container::Container(const Container& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Вызван конструктор копирования для класса Container";
}

Container::~Container() {
    cout << "Вызван деструктор для класса Container";
}

Node* Container::get_head() {
    return this->head;
}

Node* Container::get_tail() {
    return this->tail;
}

void Container::add_train(Train* Tr, int index) {
    if (index < 0 || index > count) {
        throw out_of_range("Index out of range");
    }
    
    Node* node_to_add = new Node;
    node_to_add->data = Tr;
    node_to_add->next = nullptr;
    
    if (index == 0)
        head = tail = node_to_add; 
    else {
        Node* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            if (prev->next == nullptr) {
                throw out_of_range("Index out of range");
            }
            prev = prev->next;
        }
        node_to_add->next = prev->next;
        prev->next = node_to_add;
        if (prev == tail) {
            tail = node_to_add;
        }
    }
    ++count;
}

Container& Container::delete_train(int index) {

}
