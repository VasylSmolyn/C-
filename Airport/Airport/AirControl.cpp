// AirControl.cpp

#include "AirControl.h"

AirControl::AirControl(int nTimeForProcessing)
    : PlanesControl(nTimeForProcessing)
{
}

void AirControl::Add(Plane* p)
{
    if (p)
    {
        p->setAir(true);
        m_Planes.push_back(p);
        std::cout << "#" << p->getCode() << " Asks landing" << std::endl;
    }
}

void AirControl::ProcessTick()
{
    bool bProcessing = (m_pProcessingPlane != nullptr);
    bool bFinished = m_pProcessingPlane && m_pProcessingPlane->IsFinished();

    PlanesControl::ProcessTick();

    for (auto p = m_Planes.begin(); p != m_Planes.end();)
    {
        if ((*p)->IsCrashed())
        {
            std::cout << "#" << (*p)->getCode() << " Crashed!" << std::endl;
            delete (*p);
            p = m_Planes.erase(p);
        }
        else
        {
            ++p;
        }
    }

    // todo: обробити вибір нового літака для початку посадки - "Start landing"
    // todo: обробити подію завершення посадки - "Landed"
}

void AirControl::Print() const
{
    PlanesControl::Print();
}
