#pragma once
#include "types/types.hpp"

namespace Aurex{

class IColorable{
public:
  virtual ~IColorable() = default;
  virtual Aurex::Color Color() const = 0;
  virtual void SetColor(Aurex::Color color) = 0;
  virtual float Opacity() const = 0;
  virtual void SetOpacity(float opacity) = 0;
};

}
