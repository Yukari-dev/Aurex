#pragma once
#include "types/types.hpp"

namespace Aurex{

class ISizeable{
public:
  virtual ~ISizeable() = default;
  virtual Aurex::Size Size() const = 0;
  virtual void SetSize(const Aurex::Size& size) = 0;
};

}
