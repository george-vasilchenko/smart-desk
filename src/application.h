#pragma once
#include "base/delegate/delegate.h"
#include "base/logger/logger.h"
#include "config/mapping.h"
#include "control.h"
#include "filestore.h"
#include "lcd-display.h"
#include "meter.h"
#include "models/lift.h"
#include "motor.h"
#include "repository.h"
#include <Arduino.h>

class Application
{
  private:
    FileStore m_fileStore;
    Repository m_repository;
    Display *m_display = nullptr;
    Lift m_lift;
    Control m_control;
    Motor m_motor;

    void UpdateMotor(const unsigned int &value);

  public:
    Application()
        : m_repository(&this->m_fileStore),
          m_display(new LcdDisplay()),
          m_lift(&this->m_repository,
                 new DelegateParam0<const unsigned int>(this->m_display, &Display::SetCurrentLiftHeight)),
          m_control(new Delegate(&this->m_lift, &Lift::MoveUp),
                    new Delegate(&this->m_lift, &Lift::MoveDown))
    {
    }
    ~Application()
    {
        this->m_repository.SetCurrentLevelData(this->m_lift.GetCurrentLevel());
    }

    void Update();
};

void Application::Update()
{
    this->m_control.Update();
}

void Application::UpdateMotor(const unsigned int &value)
{
    auto servoValue = map(value, 0, 100, 0, 180);
    this->m_motor.Update(servoValue);
}
