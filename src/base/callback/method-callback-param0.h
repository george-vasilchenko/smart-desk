#pragma once
#include "callback-param0.h"

template <typename TParam, typename TObject, typename TCallback>
class MethodCallbackParam0 : public CallbackParam0<TParam>
{
  private:
    void *m_object;
    TCallback m_method;

  public:
    MethodCallbackParam0(void *object, TCallback method)
        : m_object(object), m_method(method)
    {
    }

    void Invoke(TParam param0)
    {
        TObject *obj = static_cast<TObject *>(m_object);
        (obj->*m_method)(param0);
    }
};