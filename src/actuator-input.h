#pragma once

#include "Arduino.h"
#include "actuator-button.h"
#include "base/input/input.h"
#include "config/mapping.h"

class ActuatorInput : public Input<ActuatorButton>
{
  private:
    ActuatorButton m_increaseButton;
    ActuatorButton m_decreaseButton;

  public:
    ActuatorInput()
        : m_increaseButton(INCREASE_BUTTON_KEY),
          m_decreaseButton(DECREASE_BUTTON_KEY)
    {
        pinMode(BTN_INCR, INPUT);
        pinMode(BTN_DECR, INPUT);
    }

    ~ActuatorInput()
    {
    }

    void Update()
    {
        this->m_increaseButton.SetState((ActuatorButtonState)digitalRead(BTN_INCR));
        this->m_decreaseButton.SetState((ActuatorButtonState)digitalRead(BTN_DECR));
    }

    ActuatorButton *GetInput(const char *keyCode)
    {
        if (this->m_increaseButton.GetKey() == keyCode)
        {
            return &this->m_increaseButton;
        }

        if (this->m_decreaseButton.GetKey() == keyCode)
        {
            return &this->m_decreaseButton;
        }

        return nullptr;
    }
};
