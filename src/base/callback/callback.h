#pragma once

class Callback
{
  public:
    virtual ~Callback() = default;
    virtual void Invoke() = 0;
};