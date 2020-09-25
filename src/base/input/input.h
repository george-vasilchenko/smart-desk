#pragma once

template <typename TInputComponent>
class Input
{
  public:
    virtual ~Input() = default;
    virtual void Update() = 0;
    virtual TInputComponent *GetInput(const char *keyCode) = 0;
};