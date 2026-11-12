#include "Train.h"
#include <iostream>

Train::Train() {
    NAZN = "Не указан";
    NUMR = 0;
    TIME = "00:00";
}

Train::Train(const std::string& nazn, int numr, const std::string& time) {
    NAZN = nazn;
    NUMR = numr;
    TIME = time;
}

Train::Train(const Train& other) {
    NAZN = other.NAZN;
    NUMR = other.NUMR;
    TIME = other.TIME;
}

Train::~Train() {
}

std::string Train::getNAZN() const {
    return NAZN;
}

int Train::getNUMR() const {
    return NUMR;
}

std::string Train::getTIME() const {
    return TIME;
}

void Train::setNAZN(const std::string& nazn) {
    NAZN = nazn;
}

void Train::setNUMR(int numr) {
    NUMR = numr;
}

void Train::setTIME(const std::string& time) {
    TIME = time;
}

void Train::print() const {
    std::cout << "Пункт назначения: " << NAZN << std::endl;
    std::cout << "Номер поезда: " << NUMR << std::endl;
    std::cout << "Время отправления: " << TIME << std::endl;
    std::cout << "-----------------------------" << std::endl;
}