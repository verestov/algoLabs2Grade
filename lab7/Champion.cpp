#include "Champion.h"

// ==================== CHAMPIONWINNER ====================

ChampionWinner::ChampionWinner(
    const std::string& fullName,
    const std::string& championshipName)
    : fullName(fullName),
      championshipName(championshipName) {
}

ChampionWinner::~ChampionWinner() {
}

std::string ChampionWinner::getFullName() const {
    return fullName;
}

std::string ChampionWinner::getChampionshipName() const {
    return championshipName;
}

void ChampionWinner::setFullName(const std::string& fullName) {
    this->fullName = fullName;
}

void ChampionWinner::setChampionshipName(
    const std::string& championshipName) {
    this->championshipName = championshipName;
}


// ==================== COMPETITION ====================

Competition::Competition(
    const std::string& fullName,
    const std::string& championshipName,
    const std::string& competitionName,
    int year)
    : ChampionWinner(fullName, championshipName),
      competitionName(competitionName),
      year(year) {
}

Competition::~Competition() {
}

void Competition::displayInfo() const {
    std::cout << "\n===== СОРЕВНОВАНИЕ =====" << std::endl;
    std::cout << "ФИО победителя: " << fullName << std::endl;
    std::cout << "Чемпионат: " << championshipName << std::endl;
    std::cout << "Название соревнования: " << competitionName << std::endl;
    std::cout << "Год проведения: " << year << std::endl;
}

std::string Competition::getAchievement() const {
    return "Участие в соревновании";
}

std::string Competition::getCompetitionLevel() const {
    return "Общий уровень соревнования";
}

std::string Competition::getCompetitionName() const {
    return competitionName;
}

int Competition::getYear() const {
    return year;
}

void Competition::setCompetitionName(
    const std::string& competitionName) {
    this->competitionName = competitionName;
}

void Competition::setYear(int year) {
    this->year = year;
}


// ==================== COMPETITIONTYPE ====================

CompetitionType::CompetitionType(
    const std::string& fullName,
    const std::string& championshipName,
    const std::string& competitionName,
    int year,
    const std::string& type)
    : Competition(fullName, championshipName, competitionName, year),
      type(type) {
}

CompetitionType::~CompetitionType() {
}

void CompetitionType::displayInfo() const {
    Competition::displayInfo();

    std::cout << "Вид соревнования: " << type << std::endl;
}

std::string CompetitionType::getAchievement() const {
    return "Победа в соревновании вида: " + type;
}

std::string CompetitionType::getCompetitionLevel() const {
    return "Вид соревнования: " + type;
}

std::string CompetitionType::getType() const {
    return type;
}

void CompetitionType::setType(const std::string& type) {
    this->type = type;
}


// ==================== COMPETITIONTOUR ====================

CompetitionTour::CompetitionTour(
    const std::string& fullName,
    const std::string& championshipName,
    const std::string& competitionName,
    int year,
    const std::string& type,
    const std::string& tour)
    : CompetitionType(
          fullName,
          championshipName,
          competitionName,
          year,
          type),
      tour(tour) {
}

CompetitionTour::~CompetitionTour() {
}

void CompetitionTour::displayInfo() const {
    CompetitionType::displayInfo();

    std::cout << "Тур соревнования: " << tour << std::endl;
}

std::string CompetitionTour::getAchievement() const {
    return "Победа в туре: " + tour;
}

std::string CompetitionTour::getCompetitionLevel() const {
    return "Уровень соревнования: " + tour;
}

std::string CompetitionTour::getTour() const {
    return tour;
}

void CompetitionTour::setTour(const std::string& tour) {
    this->tour = tour;
}