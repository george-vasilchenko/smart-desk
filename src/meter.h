#pragma once

#include "Arduino.h"
#include "config/mapping.h"

class Meter
{
  private:
    unsigned long m_duration = 0;
    unsigned int m_distance = 0;

  public:
    Meter();
    ~Meter();
    void Refresh();
    const unsigned int &GetCurrentDistance();
};

Meter::Meter()
{
    pinMode(US_TRIG, OUTPUT);
    pinMode(US_ECHO, INPUT);
}

Meter::~Meter()
{
}

void Meter::Refresh()
{
    digitalWrite(US_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(US_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(US_TRIG, LOW);

    this->m_duration = pulseIn(US_ECHO, HIGH);
    this->m_distance = (unsigned int)(this->m_duration * 0.034 / 2);
}

const unsigned int &Meter::GetCurrentDistance()
{
    return this->m_distance;
}
