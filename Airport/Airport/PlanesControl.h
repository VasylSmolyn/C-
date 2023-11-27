// PlanesControl.h

#ifndef PLANESCONTROL_H
#define PLANESCONTROL_H

#include <iostream>
#include <vector>
#include "Plane.h"

class PlanesControl
{
protected:
    std::vector<Plane*> m_Planes;
    Plane* m_pProcessingPlane;
    int m_nTimeForProcessing;

public:
    PlanesControl(int nTimeForProcessing);

    virtual ~PlanesControl();

    virtual void Add(Plane* p);

    virtual void ProcessTick();

    Plane* PopReadyPlane();

    virtual void Print() const;

    bool Remove(int nCode); // Додано метод для видалення літака за кодом
};

#endif // PLANESCONTROL_H
