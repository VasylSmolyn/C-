// DialogManager.cpp

#include "DialogManager.h"
#include <iostream>

DialogManager::DialogManager(Airport& port) : m_refAirport(port)
{
    m_aCommands.push_back(new DlgCommand("Quit"));
}

DialogManager::~DialogManager()
{
    for (DlgCommand* cmd : m_aCommands)
    {
        delete cmd;
    }
}

void DialogManager::RegisterCommand(const char* sName, ptDlgCommandFunc pFunc)
{
    m_aCommands.push_back(new DlgCommand(sName, pFunc));
}

void DialogManager::Run()
{
    int nCommand = 1;

    while (nCommand)
    {
        std::cout << std::endl;
        for (size_t i = 0; i < m_aCommands.size(); i++)
        {
            std::cout << i << ". " << m_aCommands[i]->GetName() << std::endl;
        }

        std::cout << "Enter command:";
        std::cin >> nCommand;

        if ((nCommand > 0) && (nCommand < static_cast<int>(m_aCommands.size())))
        {
            m_aCommands[nCommand]->Run(m_refAirport);
        }
    }
}
