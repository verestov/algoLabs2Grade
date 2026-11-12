#ifndef LABSALGO_DATE_H
#define LABSALGO_DATE_H

#include <iostream>
#include <chrono>

class Date {
protected:
    int day;
    int month;
    int year;

public:
    Date();
    Date(int day, int month, int year);
    virtual ~Date();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    virtual void print() const;
};


class FullDate : public Date {
private:
    int hour;
    int minute;
    int second;

public:
    FullDate();
    FullDate(int day, int month, int year,
             int hour, int minute, int second);

    void print() const override;
    void printUS() const;
    void printEU() const;

    double daysInterval(const FullDate& other) const;
};


class FullDateProtected : protected Date {
private:
    int hour;
    int minute;
    int second;

public:
    FullDateProtected();
    FullDateProtected(int day, int month, int year,
                      int hour, int minute, int second);

    void print() const;
    void printUS() const;
    void printEU() const;

    double daysInterval(const FullDateProtected& other) const;
};


class FullDatePrivate : private Date {
private:
    int hour;
    int minute;
    int second;

public:
    FullDatePrivate();
    FullDatePrivate(int day, int month, int year,
                    int hour, int minute, int second);

    void print() const;
    void printUS() const;
    void printEU() const;

    double daysInterval(const FullDatePrivate& other) const;
};

#endif