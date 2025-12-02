#include <iostream>
#include <vector>
#include <string>
#include "CMail.h"
#include "AddressValidator.h"

using namespace std;

void printMenu() {
    cout << "\n===== МЕНЮ =====\n";
    cout << "1. Показать все адреса\n";
    cout << "2. Добавить новый адрес\n";
    cout << "3. Проверить все адреса\n";
    cout << "0. Выход\n";
    cout << "Ваш выбор: ";
}

CMail inputMail() {
    string country, region, district, city, street, house, flat, index;
    int type;

    cout << "Введите страну: ";
    getline(cin, country);

    cout << "Введите индекс: ";
    getline(cin, index);

    cout << "Введите область/регион: ";
    getline(cin, region);

    cout << "Введите район: ";
    getline(cin, district);

    cout << "Введите город: ";
    getline(cin, city);

    cout << "Введите улицу: ";
    getline(cin, street);

    cout << "Введите дом: ";
    getline(cin, house);

    cout << "Введите квартиру: ";
    getline(cin, flat);

    cout << "Введите тип адреса (1 – Россия, 2 – международный): ";
    cin >> type;
    cin.ignore();

    return CMail(country, index, region, district, city, street, house, flat, type);
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<CMail> addresses = {
        CMail("Россия", "101000", "Московская", "ЦАО", "Москва", "Арбат", "12", "5", 1),
        CMail("Россия", "620000", "Свердловская", "Ленинский", "Екатеринбург", "Мира", "33", "10", 1)
    };

    while (true) {
        printMenu();
        int choice;
        cin >> choice;
        cin.ignore(); // очищаем буфер

        if (choice == 0) {
            cout << "Выход...\n";
            break;
        }

        switch (choice) {
        case 1: { // показать все адреса
            cout << "\nСписок адресов:\n";
            int i = 1;
            for (auto& m : addresses) {
                cout << "№" << i++ << ":\n";
                cout << m.info() << "\n\n";
            }
            break;
        }

        case 2: { // добавить новый адрес
            cout << "\nДобавление нового адреса:\n";
            CMail newMail = inputMail();
            addresses.push_back(newMail);
            cout << "Адрес добавлен!\n";
            break;
        }

        case 3: { // проверить все адреса
            cout << "\nПроверка адресов:\n";
            int i = 1;
            for (auto& m : addresses) {
                cout << "Адрес №" << i++ << ":\n";
                auto errors = AddressValidator::validate(m);
                if (errors.empty()) {
                    cout << "  ? Корректен\n";
                }
                else {
                    cout << "  ? Ошибки:\n";
                    for (auto& e : errors) cout << "    - " << e << "\n";
                }
                cout << "\n";
            }
            break;
        }

        default:
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    }

    return 0;
}

