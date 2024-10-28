#include "container.h"

Container::Container() : head(nullptr), tail(nullptr), count(0) {cout << "Вызван конструктор без параметров для класса Container\n";}

Container::Container(Node* h, Node* t, const int c) : head(h), tail(t), count(c) {
    cout << "Вызван конструктор с параметрами для класса Container\n";
}

Container::Container(const Container& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Вызван конструктор копирования для класса Container\n";
}

Container::~Container() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    tail = nullptr;
    count = 0;
    cout << "Вызван деструктор для класса Container" << endl;
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
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;

    if (index == 0) {
        head = head->next;
        delete temp->data;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
    } else {
        Node* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        if (temp == tail) {
            tail = prev;
        }
        delete temp->data;
        delete temp;
    }

    --count;
    return *this;
}

void Container::display_trains() {
    Node* temp = head;
    if (count = 0) {
        cout << "Поездов нет" << endl;
        return;
    }
    while (temp != 0) {
        cout << count + 1 << " - Информация о поезде:\n";
        temp->data->display_train();
        temp = temp->next;
        count++;
    }
}

void Container::sort_trains_by_number() {
    if (count < 2) return;

    for (Node* i = head; i != nullptr; i = i->next) {
        for (Node* j = head; j->next != nullptr; j = j->next) {
            if (j->data->get_number() > j->next->data->get_number()) {
                Train* temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

void Container::search_train(const int number) {

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data->get_number() == number) {
            temp->data->display_train();
            return;
        }
        temp = temp->next;
    }
    cout << "Поезд с номером " << number << " не найден." << endl;
}

Container& Container::edit_train(int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    temp->data->edit_train();
    return *this;
}

Container& Container::operator[](int index) {
    if (index < 0 || index >= count) {
        throw out_of_range("Index out of range");
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }

    return *this;
}
