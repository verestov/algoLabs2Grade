#include <iostream>
#include "Champion.h"

using namespace std;

int main() {
    Competition competition(
        "Иванов Иван Иванович",
        "Чемпионат по программированию",
        "Программирование C++",
        2026
    );

    CompetitionType competitionType(
        "Петров Петр Петрович",
        "Олимпиада по программированию",
        "Алгоритмическое программирование",
        2026,
        "Индивидуальное"
    );

    CompetitionTour competitionTour(
        "Сидоров Алексей Сергеевич",
        "Международный чемпионат",
        "International Programming Championship",
        2026,
        "Командное",
        "Международный"
    );

    cout << "===== ПРОВЕРКА GET-МЕТОДОВ =====" << endl;

    cout << "Имя победителя: "
         << competition.getFullName() << endl;

    cout << "Название чемпионата: "
         << competition.getChampionshipName() << endl;

    cout << "Название соревнования: "
         << competition.getCompetitionName() << endl;

    cout << "Год проведения: "
         << competition.getYear() << endl;

    cout << "Вид соревнования: "
         << competitionType.getType() << endl;

    cout << "Тур соревнования: "
         << competitionTour.getTour() << endl;


    // Демонстрация методов изменения данных
    competition.setFullName("Иванов Иван Иванович");
    competition.setChampionshipName("Региональный чемпионат");

    competition.setCompetitionName("Программирование на C++");
    competition.setYear(2025);

    competitionType.setType("Индивидуальное");

    competitionTour.setTour("Федеральный");


    // Создание массива указателей на базовый класс
    ChampionWinner* winners[3];

    // Связывание указателей с объектами наследников
    winners[0] = &competition;
    winners[1] = &competitionType;
    winners[2] = &competitionTour;

    // Динамическое связывание
    cout << "\n===== ИНФОРМАЦИЯ О ПОБЕДИТЕЛЯХ =====" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "\nПОБЕДИТЕЛЬ №" << i + 1;
        winners[i]->displayInfo();
        cout << "Достижение: "
             << winners[i]->getAchievement() << endl;
        cout << winners[i]->getCompetitionLevel() << endl;
        cout << "-----------------------------" << endl;
    }
    return 0;
}