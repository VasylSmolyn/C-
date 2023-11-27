// Airport.cpp

#include "Airport.h"
#include <iostream>

Airport::Airport(const std::string& _name, Stat& rStat)
    : name(_name), landingPlanes(10, rStat), takingoffPlanes(10, rStat), m_rStat(rStat), m_pOutputPlane(nullptr)
{
}

Airport::~Airport()
{
    if (m_pOutputPlane)
    {
        delete m_pOutputPlane;
    }
}

void Airport::Add(Plane* p, bool bInAir)
{
    if (p)
    {
        p->setAir(bInAir);
        if (bInAir)
        {
            landingPlanes.Add(p);
        }
        else
        {
            takingoffPlanes.Add(p);
        }
    }
}

Plane* Airport::PopOutputPlane()
{
    if (m_pOutputPlane)
    {
        Plane* tmpPlane = m_pOutputPlane;
        m_pOutputPlane = nullptr;
        return tmpPlane;
    }
    return nullptr;
}

void Airport::ProcessTick()
{
    landingPlanes.ProcessTick();
    takingoffPlanes.ProcessTick();

    // todo: забрати літак (який успішно сів) з підпорядкування повітряного контролера,
    // і передати його під контроль наземного диспетчера
    Plane* p1 = landingPlanes.PopReadyPlane();
    if (p1 != nullptr)
    {
        takingoffPlanes.Add(p1);
    }

    // todo: забрати літак (який успішно злетів) з підпорядкування наземного диспетчера
    // і виокремити його об'єкт у змінну m_pOutputPlane - літак, що вийшов за межі аеропорту
    Plane* p2 = takingoffPlanes.PopReadyPlane();
    if (p2 != nullptr)
    {
        m_pOutputPlane = p2;
    }
}

void Airport::Print() const
{
    std::cout << "Airport: " << name << std::endl;
    std::cout << "Landing planes: " << std::endl;
    landingPlanes.Print();
    std::cout << "Taking off planes: " << std::endl;
    takingoffPlanes.Print();
    if (m_pOutputPlane)
    {
        std::cout << "Plane outside the airport: ";
        m_pOutputPlane->Print();
    }
}

bool Airport::Remove(int nCode)
{
    bool result = false;
    if (m_pOutputPlane && (nCode == m_pOutputPlane->getCode()))
    {
        delete m_pOutputPlane;
        m_pOutputPlane = nullptr;
        result = true;
    }
    if (result || landingPlanes.Remove(nCode) || takingoffPlanes.Remove(nCode))
    {
        return true;
    }
    return false;
}

Stat& Airport::getStat()
{
    return m_rStat;
}
