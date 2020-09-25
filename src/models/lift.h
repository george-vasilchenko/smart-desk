#pragma once

#include "../repository.h"
#include "base/delegate/delegate-param0.h"

#define LEVEL_CEILING 100
#define LEVEL_GROUND 1
#define LIFT_SPEED 1

class Lift
{
  private:
    unsigned int m_currentLevel;
    DelegateParam0<const unsigned int> *m_onCurrentLevelChangedDelegate;

  public:
    Lift(Repository *repository, DelegateParam0<const unsigned int> *onCurrentLevelChanged)
        : m_onCurrentLevelChangedDelegate(onCurrentLevelChanged)
    {
        this->m_currentLevel = repository->GetCurrentLevelData();
    }
    ~Lift()
    {
        delete this->m_onCurrentLevelChangedDelegate;
    }

    void MoveUp()
    {
        if (this->m_currentLevel < LEVEL_CEILING)
        {
            this->m_currentLevel += LIFT_SPEED;
        }

        if (this->m_currentLevel >= LEVEL_CEILING)
        {
            this->m_currentLevel = LEVEL_CEILING;
        }

        (*(this->m_onCurrentLevelChangedDelegate))(this->m_currentLevel);
    }

    void MoveDown()
    {
        if (this->m_currentLevel > LEVEL_GROUND)
        {
            this->m_currentLevel -= LIFT_SPEED;
        }

        if (this->m_currentLevel <= LEVEL_GROUND)
        {
            this->m_currentLevel = LEVEL_GROUND;
        }

        (*(this->m_onCurrentLevelChangedDelegate))(this->m_currentLevel);
    }

    const unsigned int &GetCurrentLevel()
    {
        return this->m_currentLevel;
    }
};
