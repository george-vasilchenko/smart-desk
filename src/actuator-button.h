#pragma once
#include "actuator-button-state.h"

class ActuatorButton
{
  private:
    const char *m_key = nullptr;
    ActuatorButtonState m_state = Low;

  public:
    ActuatorButton(const char *key)
        : m_key(key)
    {
    }

    ~ActuatorButton()
    {
    }

    const char *GetKey()
    {
        return this->m_key;
    }

    ActuatorButtonState GetState()
    {
        return this->m_state;
    }

    void SetState(ActuatorButtonState state)
    {
        this->m_state = state;
    }
};
