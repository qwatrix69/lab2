#include "container.h"
#include "train.h"
#include "check.h"

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

int main() {
    Container trains;
    int choice;

    while (true) {
        display_menu();
        cin >> choice;

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
                int number = check_input();
                cout << "Введите номер поезда для поиска" << endl;
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
