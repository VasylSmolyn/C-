// DialogManager.h

#ifndef DIALOGMANAGER_H
#define DIALOGMANAGER_H

#include "DlgCommand.h"
#include "Airport.h"
#include <vector>

class DialogManager
{
private:
    std::vector<DlgCommand*> m_aCommands;
    Airport& m_refAirport;

public:
    DialogManager(Airport& port);
    ~DialogManager();

    void RegisterCommand(const char* sName, ptDlgCommandFunc pFunc);
    void Run();
};

#endif // DIALOGMANAGER_H
