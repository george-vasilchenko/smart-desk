#pragma once

#include "Arduino.h"
#include "actuator-button.h"
#include "actuator-input.h"
#include "base/delegate/delegate.h"
#include "base/input/input.h"
#include "config/mapping.h"

class Control
{
  private:
    Input<ActuatorButton> *m_input;

    Delegate *m_onIncreaseDelegate;
    ActuatorButton &m_onIncreaseButton;

    Delegate *m_onDecreaseDelegate;
    ActuatorButton &m_onDecreaseButton;

  public:
    Control(Delegate *onIncrease, Delegate *onDecrease)
        : m_input(new ActuatorInput()),
          m_onIncreaseDelegate(onIncrease),
          m_onIncreaseButton(*(m_input->GetInput(INCREASE_BUTTON_KEY))),
          m_onDecreaseDelegate(onDecrease),
          m_onDecreaseButton(*(m_input->GetInput(DECREASE_BUTTON_KEY)))
    {
    }

    ~Control()
    {
        delete this->m_input;
        delete this->m_onIncreaseDelegate;
        delete this->m_onDecreaseDelegate;
    }

    void Update()
    {
        this->m_input->Update();

        if (this->m_onIncreaseButton.GetState() > 0)
        {
            (*(this->m_onIncreaseDelegate))();
        }

        if (this->m_onDecreaseButton.GetState() > 0)
        {
            (*(this->m_onDecreaseDelegate))();
        }
    }
};
