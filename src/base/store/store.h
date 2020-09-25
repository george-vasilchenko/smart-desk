#pragma once
class Store
{
  public:
    virtual void SaveUInt(const char *key, unsigned int value) = 0;
    virtual unsigned int LoadUInt(const char *key) = 0;
};
