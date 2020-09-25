#pragma once
#include "base/store/store.h"

class Repository
{
  private:
    unsigned int m_currentLevelData = 0;
    Store *m_store = nullptr;

  public:
    Repository(Store *store)
        : m_store(store)
    {
        // auto val = this->m_store->LoadUInt("levelData");
        this->m_currentLevelData = 33;
    }

    ~Repository()
    {
        this->m_store->SaveUInt("levelData", this->m_currentLevelData);
    }

    void SetCurrentLevelData(unsigned int value)
    {
        this->m_currentLevelData = value;
    }

    const unsigned int &GetCurrentLevelData()
    {
        return this->m_currentLevelData;
    }
};