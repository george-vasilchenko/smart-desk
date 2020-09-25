#pragma once
#include "Arduino.h"
#include "base/logger/logger.h"
#include "config/mapping.h"

class SerialLogger : public Logger
{
  private:
    HardwareSerial &m_hardwareSerial;

  public:
    SerialLogger(HardwareSerial &hardwareSerial)
        : m_hardwareSerial(hardwareSerial)
    {
        this->m_hardwareSerial.begin(HW_SERIAL_BAUDRATE);
    }
    ~SerialLogger()
    {
    }

    void WriteLine(String &data)
    {
        this->m_hardwareSerial.println(data);
    }
    void WriteLine(const char *data)
    {
        this->m_hardwareSerial.println(data);
    }
    void WriteLine(const unsigned int &data)
    {
        this->m_hardwareSerial.println(data);
    }
};
