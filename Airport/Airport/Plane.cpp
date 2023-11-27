// Plane.cpp

#include "Plane.h"

Plane::Plane(int nCode, int nServiceTime)
    : m_nCode(nCode), m_nFuel(100), m_nServiceTime(nServiceTime), m_bInAir(false), m_nSpeed(0)
{
}

int Plane::getCode() const
{
    return m_nCode;
}

bool Plane::IsFinished() const
{
    return m_nServiceTime <= 0;
}

bool Plane::IsCrashed() const
{
    return m_nFuel <= 0;
}

void Plane::ProcessTick()
{
    if (m_bInAir)
    {
        m_nFuel -= m_nSpeed; // Враховано швидкість літака при розрахунку споживання пального
        m_nServiceTime--;
    }
}

void Plane::setAir(bool bInAir)
{
    m_bInAir = bInAir;
}

void Plane::setDestinationAirport(const std::string& destinationAirport)
{
    m_sDestinationAirport = destinationAirport;
}

void Plane::setSpeed(int speed)
{
    m_nSpeed = speed;
}

int Plane::getSpeed() const
{
    return m_nSpeed;
}
