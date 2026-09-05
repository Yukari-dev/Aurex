#pragma once
#include "types/types.hpp"

namespace Forma{

class Layout{
public:
  void SetPosition(Vec2 position);
  void SetSize(Size size);

  Forma::Vec2 Position() const;
  Forma::Size Size() const;
private:
  Forma::Vec2 m_position{};
  Forma::Size m_size{};
};

}
