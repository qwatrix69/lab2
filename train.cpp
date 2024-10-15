#include "train.h"

Train::Train() : destination(""), number(0), time_of_departure("") {cout << "Вызван конструктор без параметров для класса Train";}

Train::Train(const string& d, const int& n, const string& t) : destination(d), number(n), time_of_departure(t) {
    cout << "Вызван конструктор с параметрами для класса Train";
}

Train::Train(const Train& other) : destination(other.destination), number(other.number), time_of_departure(other.time_of_departure) {
    cout << "Вызван конструктор копирования для класса Train";
}

Train::~Train() {cout << "Вызван деструктор для класса Train";}

string Train::get_destination() {
    return this->destination;
}

void Train::set_destination(const string& d) {
    this->destination = d;
}

int Train::get_number() {
    return this->number;
}

void Train::set_number(const int& n) {
    this->number = n;
}

string Train::get_time() {
    return this->time_of_departure;
}

void Train::set_time(const string& t) {
    this->time_of_departure = t;
}

void Train::display_train() {
    cout << "Информация о поезде:\n";
    cout << "Пункт назначения: " << this->get_destination() << endl;
    cout << "Номер поезда: " << this->get_number() << endl;
    cout << "Время отправления: " << this->get_time() << endl; 
}
