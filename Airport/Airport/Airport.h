// Airport.h

#ifndef AIRPORT_H
#define AIRPORT_H

#include "AirControl.h"
#include "GroundControl.h"
#include "Stat.h"

class Airport
{
private:
    std::string name;
    AirControl landingPlanes;
    GroundControl takingoffPlanes;
    Stat& m_rStat;

    Plane* m_pOutputPlane;

public:
    Airport(const std::string& _name, Stat& rStat);
    ~Airport();

    void Add(Plane* p, bool bInAir = true);
    Plane* PopOutputPlane();
    void ProcessTick();
    void Print() const;

    bool Remove(int nCode);
    Stat& getStat();
};

#endif // AIRPORT_H
