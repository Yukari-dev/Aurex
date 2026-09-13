#pragma once
#include "types/types.hpp"

namespace Forma{

class IColorable{
public:
  virtual ~IColorable() = default;
  virtual Forma::Color Color() const = 0;
  virtual void SetColor(Forma::Color color) = 0;
  virtual float Opacity() const = 0;
  virtual void SetOpacity(float opacity) = 0;
};

}
