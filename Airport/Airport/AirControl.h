// AirControl.h

#ifndef AIRCONTROL_H
#define AIRCONTROL_H

#include "PlanesControl.h"

class AirControl : public PlanesControl
{
public:
    AirControl(int nTimeForProcessing = 10);

    void ProcessTick() override;

    void Add(Plane* p) override;

    void Print() const override;
};

#endif // AIRCONTROL_H
