#include <iostream>
#include "Soft.h"

using namespace std;

int main() {

    // 1. Создание первого объекта
    Soft* soft1 = new Soft(
        "Adobe Photoshop",
        "Adobe",
        4.5,
        Data(15, 6, 2027)
    );

    // 2. Создание второго объекта
    Soft* soft2 = new Soft();

    // Использование цепочечного вызова
    soft2->setName("Microsoft Office")
         .setDeveloper("Microsoft")
         .setVolume(2.8)
         .setLicenseEnd(Data(20, 12, 2026));

    // 3. Вывод количества созданных объектов
    cout << "Количество объектов Soft: "
         << Soft::getCount() << endl;

    // 4. Вывод информации о программах
    cout << "\nИНФОРМАЦИЯ О ПРОГРАММАХ\n";

    cout << "\nПервая программа:\n";
    soft1->print();

    cout << "\nВторая программа:\n";
    soft2->print();

    // 5. Удаление объектов
    delete soft1;
    delete soft2;

    // 6. Вывод количества объектов после удаления
    cout << "\nКоличество объектов Soft после удаления: "
         << Soft::getCount() << endl;

    return 0;
}