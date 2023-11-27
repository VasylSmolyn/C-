// DlgCommand.cpp

#include "DlgCommand.h"
#include <iostream>

DlgCommand::DlgCommand(const char* sName, ptDlgCommandFunc pFunc)
    : m_sName(sName), m_pFunc(pFunc)
{
}

DlgCommand::~DlgCommand()
{
}

const char* DlgCommand::GetName() const
{
    return m_sName.c_str();
}

void DlgCommand::Run(Airport& port)
{
    if (m_pFunc)
    {
        m_pFunc(port);
    }
    else
    {
        std::cout << "Command not implemented: " << m_sName << std::endl;
    }
}
