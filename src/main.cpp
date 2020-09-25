#include "application.h"
#include "base/logger/logger.h"
#include "serial-logger.h"
#include <Arduino.h>

#define UPDATE_DELAY 15

Logger *logger = nullptr;
Application *application = nullptr;

void wait()
{
    if (UPDATE_DELAY > 0)
    {
        delay(UPDATE_DELAY);
    }
}

void setup()
{
    logger = new SerialLogger(Serial1);
    application = new Application();
}

void loop()
{
    application->Update();
    wait();
}