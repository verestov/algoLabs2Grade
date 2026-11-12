#ifndef LABSALGO_SHAPE_H
#define LABSALGO_SHAPE_H

#include <iostream>
#include <string>

class Shape {
private:
    std::string name;
    std::string dimension;
    int points;

public:
    Shape() : name("Без названия"),
              dimension("двухмерная"),
              points(0) {
        std::cout << "Создана фигура по умолчанию\n";
    }

    Shape(const std::string& name,
          const std::string& dimension,
          int points)
        : name(name), dimension(dimension), points(points) {

        if (points < 0) {
            throw std::invalid_argument("Количество точек не может быть отрицательным");
        }

        std::cout << "Создана фигура: " << name << '\n';
    }

    // Конструктор копирования
    Shape(const Shape& other)
        : name(other.name),
          dimension(other.dimension),
          points(other.points) {
        std::cout << "Скопирована фигура: " << name << '\n';
    }

    ~Shape() {
        std::cout << "Удалена фигура: " << name << '\n';
    }

    std::string getName() const {
        return name;
    }
    std::string getDimension() const {
        return dimension;
    }
    int getPoints() const {
        return points;
    }

    void setName(const std::string& name) {
        this->name = name;
    }
    void setDimension(const std::string& dimension) {
        this->dimension = dimension;
    }
    void setPoints(int points) {
        if (points < 0) {
            throw std::invalid_argument("Количество точек не может быть отрицательным");
        }
        this->points = points;
    }

    // Сравнение фигур по количеству точек
    bool operator<(const Shape& other) const {
        return points < other.points;
    }

    friend std::ostream& operator<<(std::ostream& out,
                                   const Shape& shape) {
        out << "Название: " << shape.name
            << ", размерность: " << shape.dimension
            << ", количество точек: " << shape.points << std::endl;

        return out;
    }
};

#endif
