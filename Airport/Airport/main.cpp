#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "DialogManager.h"

// Коди та класи з попередніх завдань

int main()
{
    srand(static_cast<unsigned>(time(0)));

    // Створення аеропорту та менеджера діалогів
    Stat stat;
    Airport port("Lviv", stat);
    DialogManager mgr(port);

    // Реєстрація команд
    mgr.RegisterCommand("Init", Init);
    mgr.RegisterCommand("Process", Process);
    mgr.RegisterCommand("Show", Show);
    mgr.RegisterCommand("Add", Add);
    mgr.RegisterCommand("Remove", Remove);
    mgr.RegisterCommand("StartPort", StartPort);
    mgr.RegisterCommand("StopPort", StopPort);
    mgr.RegisterCommand("Save", Save);
    mgr.RegisterCommand("Load", Load);
    mgr.RegisterCommand("Stat", DisplayStat);

    // Запуск циклу обробки команд
    mgr.Run();

    return 0;
}
