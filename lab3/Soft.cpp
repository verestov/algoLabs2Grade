#include "Soft.h"

#include <iostream>
#include <chrono>

// DATA

Data::Data() : day(1), month(1), year(2000) {
}

Data::Data(int day, int month, int year)
    : day(day), month(month), year(year) {
}

Data::~Data() {
}

int Data::getDay() const {
    return day;
}

int Data::getMonth() const {
    return month;
}

int Data::getYear() const {
    return year;
}

Data& Data::setDay(int day) {
    this->day = day;
    return *this;
}

Data& Data::setMonth(int month) {
    this->month = month;
    return *this;
}

Data& Data::setYear(int year) {
    this->year = year;
    return *this;
}

void Data::print() const {
    std::cout << day << "."
              << month << "."
              << year << std::endl;
}


// ==================== SOFT ====================

int Soft::count = 0;

Soft::Soft()
    : name("Не указано"),
      developer("Не указан"),
      volume(0.0),
      licenseEnd() {
    count++;
}

Soft::Soft(const std::string& name,
           const std::string& developer,
           double volume,
           const Data& licenseEnd)
    : name(name),
      developer(developer),
      volume(volume),
      licenseEnd(licenseEnd) {
    count++;
}

Soft::~Soft() {
    count--;
}

Soft& Soft::setName(const std::string& name) {
    this->name = name;
    return *this;
}

Soft& Soft::setDeveloper(const std::string& developer) {
    this->developer = developer;
    return *this;
}

Soft& Soft::setVolume(double volume) {
    this->volume = volume;
    return *this;
}

Soft& Soft::setLicenseEnd(const Data& licenseEnd) {
    this->licenseEnd = licenseEnd;
    return *this;
}

int Soft::getCount() {
    return count;
}

long long Soft::daysUntilLicenseEnd() const {

    using namespace std::chrono;

    year_month_day endDate{
        year{licenseEnd.getYear()},
        month{static_cast<unsigned>(licenseEnd.getMonth())},
        day{static_cast<unsigned>(licenseEnd.getDay())}
    };

    if (!endDate.ok()) {
        return -1;
    }

    auto today = floor<days>(system_clock::now());

    // Преобразование даты окончания лицензии в количество дней
    sys_days licenseDate = sys_days{endDate};

    return (licenseDate - today).count();
}

void Soft::print() const {

    std::cout << "Название программы: " << name << std::endl;
    std::cout << "Разработчик: " << developer << std::endl;
    std::cout << "Занимаемый объем: " << volume << " ГБ" << std::endl;

    std::cout << "Дата завершения лицензии: ";
    licenseEnd.print();

    long long days = daysUntilLicenseEnd();

    if (days == -1) {
        std::cout << "Некорректная дата лицензии!" << std::endl;
    }
    else if (days < 0) {
        std::cout << "Лицензия истекла "
                  << -days << " дн. назад." << std::endl;
    }
    else {
        std::cout << "До завершения лицензии осталось: "
                  << days << " дн." << std::endl;
    }

    std::cout << "-----------------------------" << std::endl;
}