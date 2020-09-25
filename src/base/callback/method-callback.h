#pragma once
#include "callback.h"

template <typename TObject, typename TCallback>
class MethodCallback : public Callback
{
  private:
    void *m_object;
    TCallback m_method;

  public:
    MethodCallback(void *object, TCallback method)
        : m_object(object), m_method(method)
    {
    }

    void Invoke()
    {
        TObject *obj = static_cast<TObject *>(m_object);
        (obj->*m_method)();
    }
};
