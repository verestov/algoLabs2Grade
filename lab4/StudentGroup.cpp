#include "StudentGroup.h"
#include <stdexcept>

StudentGroup::StudentGroup()
    : totalStudents(0),
      nonResidentStudents(0),
      foreignStudents(0) {
}

StudentGroup::StudentGroup(int total, int nonResident, int foreign)
    : totalStudents(total),
      nonResidentStudents(nonResident),
      foreignStudents(foreign) {

    if (total < 0 || nonResident < 0 || foreign < 0 ||
        nonResident > total || foreign > total) {
        throw std::invalid_argument("Некорректные данные группы!");
    }
}

// Конструктор преобразования
StudentGroup::StudentGroup(int total)
    : totalStudents(total),
      nonResidentStudents(0),
      foreignStudents(0) {

    if (total < 0) {
        throw std::invalid_argument("Количество студентов не может быть отрицательным!");
    }
}

StudentGroup::~StudentGroup() {
}

void StudentGroup::print() const {
    std::cout << "Общее количество студентов: "
              << totalStudents << std::endl;

    std::cout << "Количество иногородних студентов: "
              << nonResidentStudents << std::endl;

    std::cout << "Количество иностранных студентов: "
              << foreignStudents << std::endl;
}

// Перегрузка функции print с параметром
void StudentGroup::print(const std::string& title) const {
    std::cout << "\n" << title << std::endl;
    print();
}

std::istream& operator>>(std::istream& in, StudentGroup& group) {

    int total;
    int nonResident;
    int foreign;

    std::cout << "Введите общее количество студентов: ";
    in >> total;

    std::cout << "Введите количество иногородних студентов: ";
    in >> nonResident;

    std::cout << "Введите количество иностранных студентов: ";
    in >> foreign;

    if (in && (total < 0 || nonResident < 0 || foreign < 0 ||
               nonResident > total || foreign > total)) {
        in.setstate(std::ios::failbit);
        return in;
    }

    if (in) {
        group.totalStudents = total;
        group.nonResidentStudents = nonResident;
        group.foreignStudents = foreign;
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const StudentGroup& group) {

    out << "Общее количество студентов: "
        << group.totalStudents << std::endl;

    out << "Количество иногородних студентов: "
        << group.nonResidentStudents << std::endl;

    out << "Количество иностранных студентов: "
        << group.foreignStudents << std::endl;

    return out;
}

// Оператор + (добавление иностранных студентов)
StudentGroup StudentGroup::operator+(int count) const {

    if (count < 0) {
        throw std::invalid_argument("Количество не может быть отрицательным!");
    }

    return StudentGroup(
        totalStudents + count,
        nonResidentStudents,
        foreignStudents + count
    );
}

// Оператор - (удаление иностранных студентов)
StudentGroup StudentGroup::operator-(int count) const {

    if (count < 0 || count > foreignStudents) {
        throw std::invalid_argument("Невозможно удалить указанное количество студентов!");
    }

    return StudentGroup(
        totalStudents - count,
        nonResidentStudents,
        foreignStudents - count
    );
}

// Перегрузка оператора - для двух объектов
StudentGroup StudentGroup::operator-(const StudentGroup& other) const {

    return StudentGroup(
        totalStudents - other.totalStudents,
        nonResidentStudents - other.nonResidentStudents,
        foreignStudents - other.foreignStudents
    );
}

// Оператор присваивания
StudentGroup& StudentGroup::operator=(const StudentGroup& other) {

    if (this != &other) {
        totalStudents = other.totalStudents;
        nonResidentStudents = other.nonResidentStudents;
        foreignStudents = other.foreignStudents;
    }

    return *this;
}

int StudentGroup::getTotalStudents() const {
    return totalStudents;
}

int StudentGroup::getNonResidentStudents() const {
    return nonResidentStudents;
}

int StudentGroup::getForeignStudents() const {
    return foreignStudents;
}