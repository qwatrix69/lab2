#include "train.h"

Train::Train() : destination(""), number(0), time_of_departure("") {cout << "Вызван конструктор без параметров для класса Train\n";}

Train::Train(const string& d, const int& n, const string& t) : destination(d), number(n), time_of_departure(t) {
    cout << "Вызван конструктор с параметрами для класса Train\n";
}

Train::Train(const Train& other) : destination(other.destination), number(other.number), time_of_departure(other.time_of_departure) {
    cout << "Вызван конструктор копирования для класса Train\n";
}

Train::~Train() {cout << "Вызван деструктор для класса Train\n";}

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
    cout << "Пункт назначения: " << this->get_destination() << endl;
    cout << "Номер поезда: " << this->get_number() << endl;
    cout << "Время отправления: " << this->get_time() << endl; 
    cout << endl;
}

void Train::edit_train() {
    int choice;
    cout << "Выберите, что хотите изменить:\n";
    cout << "1. Пункт назначения\n";
    cout << "2. Номер поезда\n";
    cout << "3. Время отправления\n";
    cout << "Введите ваш выбор: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string new_destination;
            cout << "Введите новый пункт назначения: ";
            cin.ignore();
            getline(cin, new_destination);
            set_destination(new_destination);
            break;
        }
        case 2: {
            int new_number;
            cout << "Введите новый номер поезда: ";
            cin >> new_number;
            set_number(new_number);
            break;
        }
        case 3: {
            string new_time;
            cout << "Введите новое время отправления: ";
            cin.ignore();
            getline(cin, new_time);
            set_time(new_time);
            break;
        }
        default:
            cout << "Неверный выбор!" << endl;
    }
}
