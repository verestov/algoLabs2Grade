#ifndef LABSALGO_CHAMPION_H
#define LABSALGO_CHAMPION_H

#include <iostream>
#include <string>

// ==================== БАЗОВЫЙ КЛАСС ====================

class ChampionWinner {
protected:
    std::string fullName;
    std::string championshipName;

public:
    ChampionWinner(const std::string& fullName,
                   const std::string& championshipName);

    virtual ~ChampionWinner();

    // Чистые виртуальные функции
    virtual void displayInfo() const = 0;
    virtual std::string getAchievement() const = 0;
    virtual std::string getCompetitionLevel() const = 0;

    std::string getFullName() const;
    std::string getChampionshipName() const;
    void setFullName(const std::string& fullName);
    void setChampionshipName(const std::string& championshipName);
};

// ==================== КЛАСС COMPETITION ====================

class Competition : public ChampionWinner {
protected:
    std::string competitionName;
    int year;

public:
    Competition(const std::string& fullName,
                const std::string& championshipName,
                const std::string& competitionName,
                int year);

    ~Competition() override;

    void displayInfo() const override;
    std::string getAchievement() const override;
    std::string getCompetitionLevel() const override;

    std::string getCompetitionName() const;
    int getYear() const;

    void setCompetitionName(const std::string& competitionName);
    void setYear(int year);
};


// ==================== КЛАСС COMPETITIONTYPE ====================

class CompetitionType : public Competition {
protected:
    std::string type;

public:
    CompetitionType(const std::string& fullName,
                    const std::string& championshipName,
                    const std::string& competitionName,
                    int year,
                    const std::string& type);

    ~CompetitionType() override;

    void displayInfo() const override;
    std::string getAchievement() const override;
    std::string getCompetitionLevel() const override;

    std::string getType() const;
    void setType(const std::string& type);
};


// ==================== КЛАСС COMPETITIONTOUR ====================

class CompetitionTour : public CompetitionType {
private:
    std::string tour;

public:
    CompetitionTour(const std::string& fullName,
                    const std::string& championshipName,
                    const std::string& competitionName,
                    int year,
                    const std::string& type,
                    const std::string& tour);

    ~CompetitionTour() override;

    void displayInfo() const override;
    std::string getAchievement() const override;
    std::string getCompetitionLevel() const override;

    std::string getTour() const;
    void setTour(const std::string& tour);
};

#endif
