#pragma once

#include "base/store/store.h"

class FileStore : public Store
{
  public:
    FileStore()
    {
    }

    ~FileStore()
    {
    }

    unsigned int LoadUInt(const char *key)
    {
        return -1;
    }

    void SaveUInt(const char *key, unsigned int value)
    {
    }
};