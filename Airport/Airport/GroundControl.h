// GroundControl.h

#ifndef GROUNDCONTROL_H
#define GROUNDCONTROL_H

#include "PlanesControl.h"

class GroundControl : public PlanesControl
{
public:
    GroundControl(int nTimeForProcessing = 10);

    void ProcessTick() override;

    void Add(Plane* p) override;

    void Print() const override;
};

#endif // GROUNDCONTROL_H
