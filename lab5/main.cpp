#include <iostream>
#include "Date.h"

using namespace std;

int main() {

    // ЗАДАЧА 1. ОТКРЫТОЕ НАСЛЕДОВАНИЕ

    cout << "===== PUBLIC =====" << endl;

    FullDate date1(12, 5, 2026, 14, 30, 45);
    FullDate date2(20, 8, 2026, 10, 15, 30);

    // Вывод в европейском формате
    cout << "\nПервая дата:" << endl;
    date1.printEU();

    // Вывод в американском формате
    date1.printUS();

    // Вывод полной даты и времени
    date1.print();

    cout << "\nВторая дата:" << endl;
    date2.print();

    // Вычисление временного интервала
    cout << "\nИнтервал между датами: "
         << date1.daysInterval(date2)
         << " дней" << endl;


    // Преобразование указателя производного класса в указатель базового класса

    cout << "\nПРЕОБРАЗОВАНИЕ УКАЗАТЕЛЕЙ" << endl;

    FullDate* derivedPtr = new FullDate(
        15, 6, 2026, 12, 0, 0
    );

    Date* basePtr = derivedPtr;

    cout << "\nВызов функции через указатель базового класса:" << endl;
    basePtr->print();

    // Преобразование указателя базового класса обратно в указатель производного класса

    FullDate* restoredPtr = dynamic_cast<FullDate*>(basePtr);

    if (restoredPtr != nullptr) {
        cout << "\nУказатель успешно преобразован обратно:" << endl;
        restoredPtr->printUS();
    }

    delete basePtr;


    // ЗАДАЧА 2. ЗАЩИЩЕННОЕ НАСЛЕДОВАНИЕ

    cout << "\n===== PROTECTED =====" << endl;

    FullDateProtected date3(
        10, 4, 2026, 16, 45, 20
    );

    FullDateProtected date4(
        25, 4, 2026, 12, 30, 0
    );

    cout << "\nПервая дата:" << endl;
    date3.print();

    date3.printUS();
    date3.printEU();

    cout << "\nВторая дата:" << endl;
    date4.print();

    cout << "\nИнтервал между датами: "
         << date3.daysInterval(date4)
         << " дней" << endl;


    // ЗАДАЧА 3. ЗАКРЫТОЕ НАСЛЕДОВАНИЕ

    cout << "\n===== PRIVATE =====" << endl;

    FullDatePrivate date5(
        1, 3, 2026, 8, 20, 15
    );

    FullDatePrivate date6(
        15, 3, 2026, 18, 10, 30
    );

    cout << "\nПервая дата:" << endl;
    date5.print();

    date5.printUS();
    date5.printEU();

    cout << "\nВторая дата:" << endl;
    date6.print();

    cout << "\nИнтервал между датами: "
         << date5.daysInterval(date6)
         << " дней" << endl;


    return 0;
}