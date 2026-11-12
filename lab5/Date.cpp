#include "Date.h"
#include <iomanip>
#include <cmath>
#include <stdexcept>

using namespace std;
using namespace std::chrono;


// ==================== DATE ====================

Date::Date() : day(1), month(1), year(2000) {
}

Date::Date(int day, int month, int year)
    : day(day), month(month), year(year) {

    year_month_day date{
        std::chrono::year{year},
        std::chrono::month{static_cast<unsigned>(month)},
        std::chrono::day{static_cast<unsigned>(day)}
    };

    if (!date.ok()) {
        throw invalid_argument("Некорректная дата!");
    }
}

Date::~Date() {
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::print() const {
    cout << setfill('0')
         << setw(2) << day << "."
         << setw(2) << month << "."
         << year << setfill(' ') << endl;
}


// ==================== FULLDATE ====================

// Открытое наследование

FullDate::FullDate()
    : Date(), hour(0), minute(0), second(0) {
}

FullDate::FullDate(int day, int month, int year,
                   int hour, int minute, int second)
    : Date(day, month, year),
      hour(hour), minute(minute), second(second) {

    if (hour < 0 || hour > 23 ||
        minute < 0 || minute > 59 ||
        second < 0 || second > 59) {
        throw invalid_argument("Некорректное время!");
    }
}

// Переопределение функции вывода
void FullDate::print() const {
    printEU();

    cout << "Время: "
         << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second
         << setfill(' ') << endl;
}

// Американский стандарт
void FullDate::printUS() const {
    cout << "Американский формат: "
         << setfill('0')
         << setw(2) << month << "/"
         << setw(2) << day << "/"
         << year
         << setfill(' ') << endl;
}

// Европейский стандарт
void FullDate::printEU() const {
    cout << "Европейский формат: "
         << setfill('0')
         << setw(2) << day << "."
         << setw(2) << month << "."
         << year
         << setfill(' ') << endl;
}

// Вычисление временного интервала в днях
double FullDate::daysInterval(const FullDate& other) const {

    sys_seconds first =
        sys_days{year_month_day{
            std::chrono::year{year},
            std::chrono::month{static_cast<unsigned>(month)},
            std::chrono::day{static_cast<unsigned>(day)}
        }}
        + hours{hour} + minutes{minute} + seconds{second};

    sys_seconds secondDate =
        sys_days{year_month_day{
            std::chrono::year{other.year},
            std::chrono::month{static_cast<unsigned>(other.month)},
            std::chrono::day{static_cast<unsigned>(other.day)}
        }}
        + hours{other.hour} + minutes{other.minute} + seconds{other.second};

    duration<double, ratio<86400>> difference = secondDate - first;

    return abs(difference.count());
}


// ==================== FULLDATEPROTECTED ====================

// Защищенное наследование

FullDateProtected::FullDateProtected()
    : Date(), hour(0), minute(0), second(0) {
}

FullDateProtected::FullDateProtected(
    int day, int month, int year,
    int hour, int minute, int second)
    : Date(day, month, year),
      hour(hour), minute(minute), second(second) {

    if (hour < 0 || hour > 23 ||
        minute < 0 || minute > 59 ||
        second < 0 || second > 59) {
        throw invalid_argument("Некорректное время!");
    }
}

void FullDateProtected::print() const {
    printEU();

    cout << "Время: "
         << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second
         << setfill(' ') << endl;
}

void FullDateProtected::printUS() const {
    cout << "Американский формат: "
         << setfill('0')
         << setw(2) << month << "/"
         << setw(2) << day << "/"
         << year
         << setfill(' ') << endl;
}

void FullDateProtected::printEU() const {
    cout << "Европейский формат: "
         << setfill('0')
         << setw(2) << day << "."
         << setw(2) << month << "."
         << year
         << setfill(' ') << endl;
}

double FullDateProtected::daysInterval(
    const FullDateProtected& other) const {

    sys_seconds first =
        sys_days{year_month_day{
            std::chrono::year{year},
            std::chrono::month{static_cast<unsigned>(month)},
            std::chrono::day{static_cast<unsigned>(day)}
        }}
        + hours{hour} + minutes{minute} + seconds{second};

    sys_seconds secondDate =
        sys_days{year_month_day{
            std::chrono::year{other.year},
            std::chrono::month{static_cast<unsigned>(other.month)},
            std::chrono::day{static_cast<unsigned>(other.day)}
        }}
        + hours{other.hour} + minutes{other.minute} + seconds{other.second};

    duration<double, ratio<86400>> difference = secondDate - first;

    return abs(difference.count());
}


// ==================== FULLDATEPRIVATE ====================

// Закрытое наследование

FullDatePrivate::FullDatePrivate()
    : Date(), hour(0), minute(0), second(0) {
}

FullDatePrivate::FullDatePrivate(
    int day, int month, int year,
    int hour, int minute, int second)
    : Date(day, month, year),
      hour(hour), minute(minute), second(second) {

    if (hour < 0 || hour > 23 ||
        minute < 0 || minute > 59 ||
        second < 0 || second > 59) {
        throw invalid_argument("Некорректное время!");
    }
}

void FullDatePrivate::print() const {
    printEU();

    cout << "Время: "
         << setfill('0')
         << setw(2) << hour << ":"
         << setw(2) << minute << ":"
         << setw(2) << second
         << setfill(' ') << endl;
}

void FullDatePrivate::printUS() const {
    cout << "Американский формат: "
         << setfill('0')
         << setw(2) << month << "/"
         << setw(2) << day << "/"
         << year
         << setfill(' ') << endl;
}

void FullDatePrivate::printEU() const {
    cout << "Европейский формат: "
         << setfill('0')
         << setw(2) << day << "."
         << setw(2) << month << "."
         << year
         << setfill(' ') << endl;
}

double FullDatePrivate::daysInterval(
    const FullDatePrivate& other) const {

    sys_seconds first =
        sys_days{year_month_day{
            std::chrono::year{year},
            std::chrono::month{static_cast<unsigned>(month)},
            std::chrono::day{static_cast<unsigned>(day)}
        }}
        + hours{hour} + minutes{minute} + seconds{second};

    sys_seconds secondDate =
        sys_days{year_month_day{
            std::chrono::year{other.year},
            std::chrono::month{static_cast<unsigned>(other.month)},
            std::chrono::day{static_cast<unsigned>(other.day)}
        }}
        + hours{other.hour} + minutes{other.minute} + seconds{other.second};

    duration<double, ratio<86400>> difference = secondDate - first;

    return abs(difference.count());
}