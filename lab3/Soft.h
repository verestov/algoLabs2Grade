#ifndef LABSALGO_SOFT_H
#define LABSALGO_SOFT_H

#include <string>

class Data {
private:
    int day;
    int month;
    int year;

public:
    Data();

    Data(int day, int month, int year);

    ~Data();

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    Data& setDay(int day);
    Data& setMonth(int month);
    Data& setYear(int year);

    void print() const;
};


class Soft {
private:
    std::string name;
    std::string developer;
    double volume;
    Data licenseEnd;

    static int count;

public:
    Soft();

    Soft(const std::string& name,
         const std::string& developer,
         double volume,
         const Data& licenseEnd);

    ~Soft();

    Soft& setName(const std::string& name);
    Soft& setDeveloper(const std::string& developer);
    Soft& setVolume(double volume);
    Soft& setLicenseEnd(const Data& licenseEnd);

    static int getCount();

    long long daysUntilLicenseEnd() const;

    void print() const;
};

#endif
