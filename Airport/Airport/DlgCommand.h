// DlgCommand.h

#ifndef DLGCOMMAND_H
#define DLGCOMMAND_H

#include "Airport.h"

typedef void (*ptDlgCommandFunc)(Airport& port);

class DlgCommand
{
private:
    std::string m_sName;
    ptDlgCommandFunc m_pFunc;

public:
    DlgCommand(const char* sName, ptDlgCommandFunc pFunc = nullptr);
    ~DlgCommand();

    const char* GetName() const;
    void Run(Airport& port);
};

#endif // DLGCOMMAND_H
