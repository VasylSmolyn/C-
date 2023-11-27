// PlanesControl.cpp

#include "PlanesControl.h"

PlanesControl::PlanesControl(int nTimeForProcessing)
    : m_pProcessingPlane(nullptr), m_nTimeForProcessing(nTimeForProcessing)
{
}

PlanesControl::~PlanesControl()
{
    for (auto p : m_Planes)
    {
        delete p;
    }
}

void PlanesControl::Add(Plane* p)
{
    if (p)
    {
        m_Planes.push_back(p);
        std::cout << "#" << p->getCode() << " Added to control" << std::endl;
    }
}

void PlanesControl::ProcessTick()
{
    if (m_pProcessingPlane)
    {
        m_pProcessingPlane->ProcessTick();
        if (m_pProcessingPlane->IsFinished())
        {
            std::cout << "#" << m_pProcessingPlane->getCode() << " Finished processing" << std::endl;
            delete m_pProcessingPlane;
            m_pProcessingPlane = nullptr;
        }
    }
    else if (!m_Planes.empty())
    {
        m_pProcessingPlane = m_Planes.front();
        m_Planes.erase(m_Planes.begin());
        std::cout << "#" << m_pProcessingPlane->getCode() << " Started processing" << std::endl;
    }
}

Plane* PlanesControl::PopReadyPlane()
{
    Plane* readyPlane = m_pProcessingPlane;
    m_pProcessingPlane = nullptr;
    return readyPlane;
}

void PlanesControl::Print() const
{
    if (!m_Planes.empty())
    {
        std::cout << "Planes queue:" << std::endl;
        for (const auto& p : m_Planes)
        {
            std::cout << "#" << p->getCode() << " Waiting" << std::endl;
        }
    }
    else
    {
        std::cout << "Planes queue is empty." << std::endl;
    }
}

bool PlanesControl::Remove(int nCode)
{
    for (auto p = m_Planes.begin(); p != m_Planes.end(); ++p)
    {
        if ((*p)->getCode() == nCode)
        {
            std::cout << "#" << nCode << " Removed from control" << std::endl;
            delete* p;
            m_Planes.erase(p);
            return true;
        }
    }
    return false;
}
