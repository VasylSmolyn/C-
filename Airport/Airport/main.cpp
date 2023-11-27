#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "DialogManager.h"

// ���� �� ����� � ��������� �������

int main()
{
    srand(static_cast<unsigned>(time(0)));

    // ��������� ��������� �� ��������� ������
    Stat stat;
    Airport port("Lviv", stat);
    DialogManager mgr(port);

    // ��������� ������
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

    // ������ ����� ������� ������
    mgr.Run();

    return 0;
}
