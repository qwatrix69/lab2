#include "container.h"
#include "train.h"
#include "check.h"
#include "sentense_filter.h"
#include <iostream>

using namespace std;

void display_menu() {
    cout << "\n===== Меню управления поездами =====" << endl;
    cout << "1. Добавить поезд" << endl;
    cout << "2. Удалить поезд" << endl;
    cout << "3. Редактировать поезд" << endl;
    cout << "4. Показать все поезда" << endl;
    cout << "5. Сортировать поезда по номеру" << endl;
    cout << "6. Найти поезд по номеру" << endl;
    cout << "0. Выйти" << endl;
    cout << "Введите ваш выбор: ";
}

int trains_program() {
    Container trains;
    int choice;

    while (true) {
        display_menu();
        choice = check_input();

        switch (choice) {
            case 1: {
                string destination, time;
                int number, index;
                cout << "Введите пункт назначения: ";
                cin.ignore();
                getline(cin, destination);
                cout << "Введите номер поезда: ";
                number = check_input();
                cout << "Введите время отправления: ";
                getline(cin, time);
                cout << "Введите индекс, куда вставить поезд: ";
                index = check_input();

                Train* new_train = new Train(destination, number, time);
                try {
                    trains.add_train(new_train, index - 1);
                    cout << "Поезд добавлен." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                    delete new_train;
                }
                break;
            }
            case 2: {
                int index;
                cout << "Введите индекс удаляемого поезда: ";
                index = check_input();
                try {
                    trains.delete_train(index - 1);
                    cout << "Поезд удален." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "Введите индекс редактируемого поезда: ";
                index = check_input();
                try {
                    trains.edit_train(index - 1);
                    cout << "Поезд отредактирован." << endl;
                } catch (const out_of_range& e) {
                    cout << e.what() << endl;
                }
                break;
            }
            case 4: {
                trains.display_trains();
                break;
            }
            case 5: {
                trains.sort_trains_by_number();
                cout << "Поезда отсортированы по номеру." << endl;
                trains.display_trains();
                break;
            }
            case 6: {
                cout << "Введите номер поезда для поиска: ";
                int number = check_input();
                trains.search_train(number);
                break;
            }
            case 0: {
                cout << "Выход из программы." << endl;
                return 0;
            }
            default: {
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
            }
        }
    }

    return 0;
}

int words_program() {
    int wordCount;
    cout << "Введите количество слов в предложении: ";
    cin >> wordCount;

    int choice;
    cout << "Выберите источник (1 - строка, 2 - файл): ";
    cin >> choice;

    if (choice == 1) {
        cin.ignore();
        char text[8192];
        cout << "Введите текст: ";
        cin.getline(text, sizeof(text));
        SentenceFilter filter(text, wordCount, true);
        filter.result();
    } else if (choice == 2) {
        char filename[256];
        cout << "Введите имя файла: ";
        cin >> filename;
        SentenceFilter filter(filename, wordCount);
        filter.result();
    }
    return 0;
}


int main() {
    int choice;
    while (true) {
        cout << "Выберите тип задания:" << endl;
        cout << "1 - Стандартные потоки" << endl;
        cout << "2 - Файловые и строковые потоки" << endl;
        cout << "3 - Выход" << endl;
        choice = check_input();

        switch (choice) {
            case 1:
                trains_program();
                break;
            case 2:
                words_program();
                break;
            case 3:
                cout << "Завершение работы." << endl;
                return 0;
            default:
                cout << "Неверный выбор! Попробуйте снова." << endl;
                break;
        }
    }
}
