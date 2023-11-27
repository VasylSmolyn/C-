// GroundControl.cpp

#include "GroundControl.h"

GroundControl::GroundControl(int nTimeForProcessing)
    : PlanesControl(nTimeForProcessing)
{
}

void GroundControl::Add(Plane* p)
{
    if (p)
    {
        p->setAir(false);
        m_Planes.push_back(p);
        std::cout << m_rStat.getTimer() << ": #" << p->getCode() << " Ready to take off" << std::endl;
    }
}

void GroundControl::ProcessTick()
{
    PlanesControl::ProcessTick();

    for (auto p = m_Planes.begin(); p != m_Planes.end();)
    {
        if ((*p)->IsCrashed())
        {
            std::cout << m_rStat.getTimer() << ": #" << (*p)->getCode() << " Crashed!" << std::endl;
            delete (*p);
            p = m_Planes.erase(p);
        }
        else
        {
            ++p;
        }
    }

    // todo: обробити вибір нового літака для початку зльоту - "Begin to take off"
    // todo: обробити подію завершення зльоту - "Took off"
}

void GroundControl::Print() const
{
    PlanesControl::Print();
}
