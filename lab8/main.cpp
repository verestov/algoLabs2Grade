
#include <iostream>
#include "Array.h"
#include "Shape.h"

int main() {
    // 1. Тестирование на типе int
    std::cout << "\n===== МАССИВ INT =====\n";

    Array<int, 5> intArray = {10, 25, 3, 47, 15};

    std::cout << "Элементы массива: ";
    intArray.print();

    std::cout << "Максимум: " << intArray.getMax() << '\n';
    std::cout << "Минимум: " << intArray.getMin() << '\n';

    Array<int, 5> anotherIntArray = {1, 2, 3, 4, 5};

    Array<int, 5> difference = intArray - anotherIntArray;

    std::cout << "Результат вычитания: ";
    difference.print();

    // Проверка присваивания
    Array<int, 5> copiedIntArray;
    copiedIntArray = intArray;

    std::cout << "После присваивания: ";
    copiedIntArray.print();


    // 2. Тестирование на типе double
    std::cout << "\n===== МАССИВ DOUBLE =====\n";

    Array<double, 4> doubleArray = {2.5, 8.7, 1.2, 5.4};

    std::cout << "Элементы массива: ";
    doubleArray.print();

    std::cout << "Максимум: " << doubleArray.getMax() << '\n';
    std::cout << "Минимум: " << doubleArray.getMin() << '\n';


    // 3. Тестирование на типе char
    std::cout << "\n===== МАССИВ CHAR =====\n";

    Array<char, 5> charArray = {'a', 'z', 'c', 'b', 'x'};

    std::cout << "Элементы массива: ";
    charArray.print();

    std::cout << "Максимум: " << charArray.getMax() << '\n';
    std::cout << "Минимум: " << charArray.getMin() << '\n';


    // 4. Тестирование на пользовательском типе Shape
    std::cout << "\n===== МАССИВ SHAPE =====\n";

    Array<Shape, 4> shapeArray = {
        Shape("Квадрат", "двухмерная", 4),
        Shape("Куб", "трехмерная", 8),
        Shape("Треугольник", "двухмерная", 3),
        Shape("Пирамида", "трехмерная", 5)
    };

    std::cout << "\nВсе фигуры:\n";
    shapeArray.print();

    std::cout << "\nФигура с максимальным количеством точек:\n";
    std::cout << shapeArray.getMax() << '\n';

    std::cout << "\nФигура с минимальным количеством точек:\n";
    std::cout << shapeArray.getMin() << '\n';


    // Проверка копирования пользовательского типа
    std::cout << "\n===== КОПИРОВАНИЕ SHAPE =====\n";

    Array<Shape, 4> copiedShapeArray = shapeArray;

    copiedShapeArray.print();

    return 0;
}
