#include <iostream>
#include "StudentGroup.h"

using namespace std;

int main() {

    // 1. Создание объектов через конструкторы
    StudentGroup group1(30, 10, 5);
    StudentGroup group2(20, 7, 3);

    cout << "ИСХОДНЫЕ ДАННЫЕ" << endl;

    group1.print("Первая группа:");
    group2.print("Вторая группа:");


    // 2. Проверка перегрузки функции print
    cout << "\nПЕРЕГРУЗКА ФУНКЦИИ" << endl;

    group1.print();
    group1.print("Информация о первой группе");


    // 3. Проверка оператора вывода <<
    cout << "\nОПЕРАТОР ВЫВОДА" << endl;

    cout << group1 << endl;


    // 4. Проверка оператора ввода >>
    cout << "\nОПЕРАТОР ВВОДА" << endl;

    StudentGroup group3;

    cin >> group3;

    if (!cin) {
        cerr << "Ошибка ввода данных!" << endl;
        return 1;
    }

    cout << "\nВведенная группа:" << endl;
    cout << group3 << endl;


    // 5. Проверка оператора +
    cout << "\nОПЕРАТОР +" << endl;

    group1 = group1 + 3;

    cout << "После добавления 3 иностранных студентов:" << endl;
    cout << group1 << endl;


    // 6. Проверка оператора -
    cout << "\nОПЕРАТОР - (С ЦЕЛЫМ ЧИСЛОМ)" << endl;

    group1 = group1 - 2;

    cout << "После удаления 2 иностранных студентов:" << endl;
    cout << group1 << endl;


    // 7. Проверка перегрузки оператора -
    cout << "\nОПЕРАТОР - (С ДРУГИМ ОБЪЕКТОМ)" << endl;

    StudentGroup difference = group1 - group2;

    cout << "Разница между первой и второй группами:" << endl;
    cout << difference << endl;


    // 8. Проверка конструктора преобразования
    cout << "\nКОНСТРУКТОР ПРЕОБРАЗОВАНИЯ" << endl;

    StudentGroup group4 = 25;

    cout << "Группа, созданная преобразованием из int:" << endl;
    cout << group4 << endl;


    // 9. Проверка оператора присваивания
    cout << "\nОПЕРАТОР ПРИСВАИВАНИЯ" << endl;

    group4 = group1;

    cout << "После присваивания group4 = group1:" << endl;
    cout << group4 << endl;


    return 0;
}