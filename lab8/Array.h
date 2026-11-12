#ifndef LABSALGO_ARRAY_H
#define LABSALGO_ARRAY_H

#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <typename T, int N>
class Array {
private:
    T elements[N]{};

public:
    Array() {
        std::cout << "Вызван конструктор по умолчанию\n";
    }

    // Конструктор со списком элементов
    Array(std::initializer_list<T> values) {
        if (values.size() > N) {
            throw std::invalid_argument("Слишком много элементов для массива");
        }

        int i = 0;
        for (const T& value : values) {
            elements[i++] = value;
        }

        std::cout << "Вызван конструктор со списком элементов\n";
    }

    // Конструктор копирования
    Array(const Array& other) {
        for (int i = 0; i < N; i++) {
            elements[i] = other.elements[i];
        }

        std::cout << "Вызван конструктор копирования\n";
    }

    ~Array() {
        std::cout << "Вызван деструктор массива\n";
    }

    // Оператор присваивания
    Array& operator=(const Array& other) {
        if (this != &other) {
            for (int i = 0; i < N; i++) {
                elements[i] = other.elements[i];
            }
        }

        return *this;
    }

    // Оператор поэлементного вычитания
    Array operator-(const Array& other) const {
        Array result;

        for (int i = 0; i < N; i++) {
            result.elements[i] = elements[i] - other.elements[i];
        }

        return result;
    }

    const T& getMax() const {
        const T* maxElement = &elements[0];

        for (int i = 1; i < N; i++) {
            if (*maxElement < elements[i]) {
                maxElement = &elements[i];
            }
        }

        return *maxElement;
    }

    const T& getMin() const {
        const T* minElement = &elements[0];

        for (int i = 1; i < N; i++) {
            if (elements[i] < *minElement) {
                minElement = &elements[i];
            }
        }

        return *minElement;
    }

    // Доступ к элементу по индексу
    T& operator[](int index) {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Некорректный индекс");
        }

        return elements[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= N) {
            throw std::out_of_range("Некорректный индекс");
        }

        return elements[index];
    }

    // Вывод массива
    void print() const {
        for (int i = 0; i < N; i++) {
            std::cout << elements[i] << " ";
        }

        std::cout << '\n';
    }

    static constexpr int getSize() {
        return N;
    }
};

#endif

