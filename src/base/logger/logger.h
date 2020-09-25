#pragma once
#include <Arduino.h>

class Logger
{
  public:
    virtual ~Logger() = default;
    virtual void WriteLine(String &data);
    virtual void WriteLine(const char *data);
    virtual void WriteLine(const unsigned int &data);
};
