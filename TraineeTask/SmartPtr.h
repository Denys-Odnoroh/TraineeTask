#pragma once

template <typename T>
class SmartPtr
{
private:
  T* p;
  int* count;
public:
  SmartPtr()
  {
    count = new int;
    (*count) = 0;
    p = nullptr;
  }

  SmartPtr(T* pointer)
  {
    count = new int;
    (*count) = 1;
    p = pointer;
  }

  SmartPtr(const SmartPtr& object)
  {
    p = object.p;
    count = object.count;
    (*count)++;
  }

  SmartPtr& operator=(const SmartPtr& obj)
  {
    p = obj.p;
    (*count)++;
    return *this;
  }

  SmartPtr& operator=(T* obj)
  {
    p = obj;
    (*count)++;
    return *this;
  }

  ~SmartPtr()
  {
    if (p != nullptr)
    {
      (*count)--;
      if ((*count) == 0)
      {
        delete p;
        delete count;
      }
    }
  }

  T* get()
  {
    return p;
  }

  T* operator->()
  {
    return p;
  }

  T& operator*()
  {
    return *p;
  }

  bool operator==(const T* obj)
  {
    return p == obj;
  }

  bool operator!=(const T* obj)
  {
    return p != obj;
  }
};
