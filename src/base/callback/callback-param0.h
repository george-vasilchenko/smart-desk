#pragma once

template <typename TParam>
class CallbackParam0
{
  public:
    virtual ~CallbackParam0() = default;
    virtual void Invoke(TParam param0) = 0;
};
