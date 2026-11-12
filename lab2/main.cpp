#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

#include "Train.h"

using namespace std;

int main() {

    // 1. Создание двух объектов через конструктор с параметрами
    Train train1("Москва", 125, "08:30");
    Train train2("Санкт-Петербург", 240, "12:45");

    // 2. Создание третьего объекта путем копирования второго
    Train train3(train2);

    // 3. Вывод информации об объектах
    cout << "ИНФОРМАЦИЯ ОБ ОБЪЕКТАХ" << endl;

    cout << "\nПервый поезд:" << endl;
    train1.print();

    cout << "\nВторой поезд:" << endl;
    train2.print();

    cout << "\nТретий поезд (копия второго):" << endl;
    train3.print();


    // 4. Создание массива из восьми объектов
    Train RASP[8];

    // Открытие текстового файла
    ifstream file("trains.txt");

    if (!file.is_open()) {
        cerr << "Ошибка открытия файла trains.txt!" << endl;
        return 1;
    }

    // 5. Чтение данных из файла
    string line;

    for (int i = 0; i < 8; i++) {

        if (!getline(file, line)) {
            cerr << "Ошибка: в файле недостаточно данных!" << endl;
            return 1;
        }

        stringstream ss(line);

        string nazn;
        string numr;
        string time;

        getline(ss, nazn, ';');
        getline(ss, numr, ';');
        getline(ss, time, ';');

        try {
            RASP[i].setNAZN(nazn);
            RASP[i].setNUMR(stoi(numr));
            RASP[i].setTIME(time);
        }
        catch (...) {
            cerr << "Ошибка чтения данных в строке " << i + 1 << endl;
            return 1;
        }
    }

    file.close();


    // 6. Сортировка массива по номерам поездов
    sort(RASP, RASP + 8, [](const Train& a, const Train& b) {
        return a.getNUMR() < b.getNUMR();
    });


    // Вывод отсортированного расписания
    cout << "\nОТСОРТИРОВАННОЕ РАСПИСАНИЕ" << endl;

    for (int i = 0; i < 8; i++) {
        RASP[i].print();
    }


    // 7. Поиск поезда по введенному номеру
    int searchNum;

    cout << "\nВведите номер поезда для поиска: ";
    cin >> searchNum;

    bool found = false;

    for (int i = 0; i < 8; i++) {

        if (RASP[i].getNUMR() == searchNum) {
            cout << "\nНайден поезд:" << endl;
            RASP[i].print();

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nПоезд с номером " << searchNum
             << " не найден!" << endl;
    }

    return 0;
}