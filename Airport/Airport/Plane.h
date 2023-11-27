// Plane.h

#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <string>

class Plane
{
private:
    int m_nCode;
    int m_nFuel;
    int m_nServiceTime;
    bool m_bInAir;
    std::string m_sDestinationAirport; // Додано поле для зберігання коду аеропорту призначення
    int m_nSpeed;                       // Додано поле для зберігання швидкості літака

public:
    Plane(int nCode, int nServiceTime);

    int getCode() const;
    bool IsFinished() const;
    bool IsCrashed() const;

    void ProcessTick();
    void setAir(bool bInAir);
    void setDestinationAirport(const std::string& destinationAirport); // Додано метод для встановлення аеропорту призначення
    void setSpeed(int speed);                                          // Додано метод для встановлення швидкості літака
    int getSpeed() const;                                              // Додано метод для отримання швидкості літака
};

#endif // PLANE_H
