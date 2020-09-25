#pragma once
#include "..\callback\callback-param0.h"
#include "..\callback\method-callback-param0.h"

template <typename TParam>
class DelegateParam0
{
  private:
    CallbackParam0<TParam> *m_callback = nullptr;

  public:
    template <typename TObject, typename TCallback>
    DelegateParam0(TObject *object, TCallback callback)
        : m_callback(new MethodCallbackParam0<TParam, TObject, TCallback>(object, callback))
    {
    }
    ~DelegateParam0()
    {
        delete this->m_callback;
    }

    void operator()(TParam param0)
    {
        return m_callback->Invoke(param0);
    }
};
