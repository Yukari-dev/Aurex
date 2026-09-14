#pragma once
#include "types/types.hpp"

namespace Aurex{

class IPositionable{
public:
  virtual ~IPositionable() = default;
  virtual Vec2 Position() const = 0;
  virtual void SetPosition(const Vec2& pos) = 0;
};

}
