#ifndef LABSALGO_STUDENTGROUP_H
#define LABSALGO_STUDENTGROUP_H


#include <iostream>
#include <string>

class StudentGroup {
private:
    int totalStudents;
    int nonResidentStudents;
    int foreignStudents;

public:
    StudentGroup();

    StudentGroup(int total, int nonResident, int foreign);

    StudentGroup(int total);

    ~StudentGroup();

    void print() const;
    void print(const std::string& title) const;

    friend std::istream& operator>>(std::istream& in, StudentGroup& group);

    friend std::ostream& operator<<(std::ostream& out, const StudentGroup& group);

    StudentGroup operator+(int count) const;

    StudentGroup operator-(int count) const;

    StudentGroup operator-(const StudentGroup& other) const;

    StudentGroup& operator=(const StudentGroup& other);

    int getTotalStudents() const;
    int getNonResidentStudents() const;
    int getForeignStudents() const;
};

#endif