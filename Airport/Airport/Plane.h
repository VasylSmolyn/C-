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
    std::string m_sDestinationAirport; // ������ ���� ��� ��������� ���� ��������� �����������
    int m_nSpeed;                       // ������ ���� ��� ��������� �������� �����

public:
    Plane(int nCode, int nServiceTime);

    int getCode() const;
    bool IsFinished() const;
    bool IsCrashed() const;

    void ProcessTick();
    void setAir(bool bInAir);
    void setDestinationAirport(const std::string& destinationAirport); // ������ ����� ��� ������������ ��������� �����������
    void setSpeed(int speed);                                          // ������ ����� ��� ������������ �������� �����
    int getSpeed() const;                                              // ������ ����� ��� ��������� �������� �����
};

#endif // PLANE_H
