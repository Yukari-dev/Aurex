#pragma once
#include "types/types.hpp"

namespace Forma{

class ISizeable{
public:
  virtual ~ISizeable() = default;
  virtual Forma::Size Size() const = 0;
  virtual void SetSize(const Forma::Size& size) = 0;
};

}
