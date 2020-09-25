#pragma once
#include "..\callback\callback.h"
#include "..\callback\method-callback.h"

class Delegate
{
  private:
    Callback *m_callback = nullptr;

  public:
    template <typename TObject, typename TCallback>
    Delegate(TObject *object, TCallback callback)
        : m_callback(new MethodCallback<TObject, TCallback>(object, callback))
    {
    }
    ~Delegate()
    {
        delete this->m_callback;
    }

    void operator()()
    {
        return m_callback->Invoke();
    }
};
