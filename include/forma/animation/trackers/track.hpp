#pragma once
#include <math.hpp>
#include <typeinfo>

namespace Forma{

class ITrackable{
public:
  virtual ~ITrackable() = default;
  
  template <typename T>
  void From(const T& value) {
    SetFrom(&value, typeid(T));
  }

  template <typename T>
  void To(const T& value){
    SetTo(&value, typeid(T));
  }

  virtual void SetDelay(float delay) = 0;
  virtual void SetDuration(float duration) = 0;
  virtual void SetEase(Axiom::EaseType ease) = 0;

private:
  virtual void SetFrom(const void* value, const std::type_info& type) = 0;
  virtual void SetTo(const void* value, const std::type_info& type) = 0;
};

}
